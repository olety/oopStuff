//
//  main.cpp
//  GenericStack
//
//  Created by Oleksii Kyrylchuk on 12/6/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"

int main(int argc, const char * argv[]) {
    Stack<int> a;
    a.push(4);
    a.push(2);
    a.push(3);
    std::cout << a.readTop() << std::endl;
    std::cout << a.pop() << " "
              << a.pop() << " "
              << a.pop() << " "
//              << a.pop() 
              << std::endl;
    return 0;
}
