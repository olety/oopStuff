//
//  ArabianNumber.cpp
//  Numbers
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "ArabianNumber.hpp"

ArabianNumber::ArabianNumber( int number ){
    this->number = number;
}

void ArabianNumber::print(){
    std::cout << this->number << std::endl;
}