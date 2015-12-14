//
//  Stack.hpp
//  GenericStack
//
//  Created by Oleksii Kyrylchuk on 12/6/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#include <vector>

template <typename T>
class Stack{
public:
    T pop();
    void push (T elem);
    T readTop();
    Stack();
    ~Stack();
private:
    std::vector<T> stack;
};
#include "Stack.cpp"
#endif /* Stack_hpp */
