//
//  GenericStack.hpp
//  RPN-Stack
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef GenericStack_hpp
#define GenericStack_hpp

#include <iostream>
#include <vector>
#include "Exception.hpp"

template<typename T>
class GenericStack {
public:
    unsigned long getSize();
    void push( T elem );
    T pop();
    T readTop();
    GenericStack();
    ~GenericStack();
private:
    std::vector<T> stack;
};


#include "GenericStack.cpp"
#endif /* GenericStack_hpp */
