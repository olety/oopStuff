//
//  main.cpp
//  complex
//
//  Created by Oleksii Kyrylchuk on 10/25/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include "ComplexNum.hpp"

int main(int argc, const char * argv[]) {
    ComplexNum num1(1,2), num2(3,4), num3;
    std::cin >> num1;
    std::cin >> num2;
    std::cout << "Number # 1 : " << num1 << std::endl << "Number # 2 : " << num2 << std::endl;
    num3 = num1 + num2;
    std::cout << "Sum : " << num3 << std::endl;
    num3 = num1 - num2;
    std::cout << "Difference : " << num3 << std::endl;
    num3 = num1 * num2;
    std::cout << "Product : " << num3 << std::endl; // (1+2i)*(3+4i) = -5+10i
    num3 = num1 / num2;
    std::cout << "Quotient : " << num3 << std::endl; // (1+2i)/(3+4i) = 0.44+0.08i
    return 0;
}
