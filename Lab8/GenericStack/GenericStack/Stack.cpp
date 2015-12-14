//
//  Stack.cpp
//  GenericStack
//
//  Created by Oleksii Kyrylchuk on 12/6/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Stack_cpp
#define Stack_cpp
#include "Stack.hpp"

template <typename T>
Stack<T>::Stack(){
    std::cout << "Constructor" << std::endl;
    stack.resize(0);
}

template <typename T>
Stack<T>::~Stack(){
    std::cout << "Destructor start" << std::endl;
    stack.erase(stack.begin(),stack.end());
    std::cout << "Destructor end" << std::endl;
}


template <typename T>
void Stack<T>::push(T elem){
    stack.resize(stack.size()+1);
    stack[stack.size()-1] = elem;
}

template <typename T>
T Stack<T>::pop(){
    if ( stack.size() < 1 ){
        std::cerr << "\nCan't pop that!\n" << std::endl;
        return NULL;
    }
    T elem = stack[stack.size()-1];
    stack.erase(stack.end()-1);
    return elem;
}

template <typename T>
T Stack<T>::readTop(){
    return stack[stack.size()-1];
}

#endif /* Stack_cpp */