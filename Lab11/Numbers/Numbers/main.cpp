//
//  main.cpp
//  Numbers
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include "RomanNumber.hpp"
int main(int argc, const char * argv[]) {
//    ArabianNumber arab(1958);
    RomanNumber *roman;
    try {
        roman = new RomanNumber(1958);
    } catch ( Exception ex ){
        ex.printException();
        ex.terminate();
    }
    roman->ArabianNumber::print();
    roman->print();
    return 0;
}
