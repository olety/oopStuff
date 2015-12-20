//
//  GenericStack.cpp
//  RPN-Stack
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//
#ifndef GenericStack_cpp
#define GenericStack_cpp
#include "GenericStack.hpp"

template <typename T>
GenericStack<T>::GenericStack(){
    stack.resize(0);
}

template <typename T>
GenericStack<T>::~GenericStack() {
    stack.erase(stack.begin(),stack.end());
}

template <typename T>
void GenericStack<T>::push( T elem ) {
//    stack.resize(stack.size+1);
//    stack[stack.size-1] = elem;
    stack.push_back(elem);
}

template <typename T>
T GenericStack<T>::pop() {
    T elem;
    try{
    elem = readTop();
    } catch ( Exception& ex ){
        ex.printException();
        return NULL;
    }
    stack.pop_back();
    return elem;
}

template <typename T>
T GenericStack<T>::readTop() {
    T elem;
    try{
        if ( stack.size() > 0 ){
            elem = stack[stack.size()-1];
        } else {
            throw Exception(1);
        }
    } catch (const std::out_of_range exception){
        std::cerr << "Stack element out of range error: " << exception.what() << std::endl;
        throw Exception(1);
        return NULL;
    }
    return elem;
}

template <typename T>
unsigned long GenericStack<T>::getSize(){
    return stack.size();
}


#endif /*GenericStack_cpp*/
