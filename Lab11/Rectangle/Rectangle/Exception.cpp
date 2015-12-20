//
//  Exception.cpp
//  Rectangle
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "Exception.hpp"

Exception::Exception( int numException ){
    this->numException = numException;
}

void Exception::printException(){
    switch ( this->numException ){
        case 0:
            std::cout << "Bad rect side value exception." << std::endl;
            break;
        case 1:
            std::cout << "Rect attribute number out of range exception." << std::endl;
            break;
        default:
            std::cout << "Unknown exception." << std::endl;
            break;
    }
}

int Exception::getNumException(){
    return this->numException;
}