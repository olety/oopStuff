//
//  Exception.cpp
//  Numbers
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "Exception.hpp"

Exception::Exception(int numException){
    this->numException = numException;
}

void Exception::printException(){
    switch (this->numException) {
        case 0:
            std::cout << "Roman number can't be lower than one exception." << std::endl;
            break;
        default:
            std::cout << "Unknown exception." << std::endl;
            break;
    }
}

void Exception::terminate(){
    exit(this->numException);
}