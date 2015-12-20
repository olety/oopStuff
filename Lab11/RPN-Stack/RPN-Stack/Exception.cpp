//
//  Exception.cpp
//  RPN-Stack
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "Exception.hpp"
Exception::Exception( int numExc ){
    numException = numExc;
}

void Exception::printException(){
    switch (numException){
        case 1 :
            std::cerr << "Can't pop element out of an empty stack exception." << std::endl;
            exit(1);
            break;
        case 2 :
            std::cerr << "Can't divide by zero exception." << std::endl;
            exit(2);
            break;
        case 3 :
            std::cerr << "Bad notation exception." << std::endl;
            exit(3);
            break;
        default :
            std::cerr << "Unknown error." << std::endl;
            exit(-1);
            break;
    }
}

int Exception::getNum(){
    return numException;
}
