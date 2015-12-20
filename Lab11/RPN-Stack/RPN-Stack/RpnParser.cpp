//
//  RpnParser.cpp
//  RPN-Stack
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef RpnParser_cpp
#define RpnParser_cpp

#include "RpnParser.hpp"

template <typename T>
RpnParser<T>::RpnParser ( GenericStack<T> stack, bool debugMode ){
    this->stack = stack;
    this->debugMode = debugMode;
}

template <typename T>
T RpnParser<T>::parse ( std::string string ){
    std::string subString;
    std::stringstream stream;
    T tempNum;
    for ( std::string::iterator it = string.begin(); it != string.end(); it++ ){
        if ( isdigit( *it ) ){
            subString.push_back(*it);
        } else {
            try{
                switch (*it){
                    case '+':
                        if ( stack.getSize() <= 1 ){
                            throw Exception(3);
                        }
                        stack.push(stack.pop()+stack.pop());
                        if ( debugMode ){
                            std::cout << "+ : " << stack.readTop() << std::endl;
                        }
                        break;
                    case '-':
                        if ( stack.getSize() <= 1 ){
                            throw Exception(3);
                        }
                        tempNum = stack.pop();
                        stack.push(stack.pop()-tempNum);
                        if ( debugMode ){
                            std::cout << "- : " << stack.readTop() << std::endl;
                        }
                        break;
                    case '/':
                        if ( stack.getSize() <= 1 ){
                            throw Exception(3);
                        }
                        if ( (tempNum = stack.pop()) == 0 )
                            throw Exception(2);
                        stack.push(stack.pop()/tempNum);
                        if ( debugMode ){
                            std::cout << "/ : " << stack.readTop() << std::endl;
                        }
                        break;
                    case '*':
                        if ( stack.getSize() <= 1 ){
                            throw Exception(3);
                        }
                        stack.push(stack.pop()*stack.pop());
                        if ( debugMode ){
                            std::cout << "* : " << stack.readTop() << std::endl;
                        }
                        break;
                    case '.':
                        subString.push_back(*it);
                        break;
                    case ' ':
                        if ( subString != "" ){
                            stream.str(subString);
                            stream >> tempNum;
                            stream.unget();
                            if ( debugMode ){
                                std::cout << "-------------------" << std::endl
                                          << "Stream : " << stream.str() << std::endl
                                          << "String : " << subString << std::endl
                                          << "Number : " << tempNum << std::endl
                                          << "-------------------" << std::endl;
                            }
                            subString.erase(subString.begin(), subString.end());
                            stack.push(tempNum);
                            tempNum = 0;
                        }
                        break;
                    default:
                        throw Exception(3);
                        break;
                }
            } catch( Exception ex ){
                throw ex;
            }
        }
    }
    return stack.pop();
}

template <typename T>
void RpnParser<T>::setDebugMode( bool debugMode ){
    this->debugMode = debugMode;
}

#endif /* RpnParser_cpp */
