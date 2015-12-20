//
//  main.cpp
//  RPN-Stack
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "GenericStack.hpp"
#include "RpnParser.hpp"
#include "Exception.hpp"

// Test expression here :
// ((4.5+5)/(3-7))*5 = " 4.5 5 + 3 7 - / 5 * " = -11.875
int main(int argc, const char * argv[]) {
    GenericStack<float> stack;
    RpnParser<float> parser(stack);
    std::string expression, subExpr;
    
    std::cout << "DebugMode on/off?" << std::endl;
    
    std::cin >> expression;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //otherwise it'd skip the expression inputting
    
    std::transform(expression.begin(), expression.end(), expression.begin(), ::tolower);
    
    if ( expression == "on" or expression == "y" or expression == "yes" ){
        parser.setDebugMode(true);
    }
    
    std::cout << "Input your RPN expression below : " << std::endl;
    
    if ( !std::getline(std::cin, expression) ){
        std::cerr << "Something went wrong while trying to read your expression." << std::endl;
        return -1;
    }
    
    try{
        std::cout << parser.parse(expression) << std::endl;
    } catch ( Exception ex ){
        ex.printException();
    }
    return 0;
}
