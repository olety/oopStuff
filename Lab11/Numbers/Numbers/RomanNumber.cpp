//
//  RomanNumber.cpp
//  Numbers
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "RomanNumber.hpp"

RomanNumber::RomanNumber(int number):ArabianNumber(number){
    if ( number < 1 ){
        throw Exception(0);
    }
}

void RomanNumber::print(){
    int tempNum = this->number;
    while ( tempNum >= 1000 ){
        tempNum -= 1000;
        std::cout << this->thousand;
    }
    if ( tempNum >= 900 ){ // tempNum is <1000 right now
        tempNum-=900;
        std::cout << this->hundred << this->thousand; // 'CM' = 900
    }
    if ( tempNum >= 500 ){ // tempNum is <900 rn
        tempNum-=500;
        std::cout << this->fiveHundred;
    }
    if ( tempNum >= 400 ){ // tempNum is <500 rn
        tempNum -= 400;
        std::cout << this->hundred << this->fiveHundred; // 'CD' = 400
    }
    while ( tempNum >= 100 ){ // tempNum is <400 rn
        tempNum -= 100;
        std::cout << this->hundred;
    }
    if ( tempNum >= 90 ){ // tempNum is <100
        tempNum -= 90;
        std::cout << this->ten << this->hundred; // 'XC' = 90
    }
    if ( tempNum >= 50 ){ // tempNum is <90
        tempNum -= 50;
        std::cout << this->fifty;
    }
    if ( tempNum >= 40 ){ // tempNum is <50
        tempNum -= 40;
        std::cout << this->ten << this->fifty; // 'XL' = 40
    }
    while ( tempNum >= 10 ){
        tempNum -= 10;
        std::cout << this->ten;
    }
    if ( tempNum >= 9 ){ // tempNum is <10 rn
        tempNum -= 9;
        std::cout << this->one << this->ten; // 'IX' = 9
    }
    if ( tempNum >= 5 ){ // tempNum is <9 rn
        tempNum -= 5;
        std::cout << this->five;
    }
    if ( tempNum >= 4 ){ // tempNum is <5 rn
        tempNum -= 4;
        std::cout << this->one << this->five; // 'IV' = 4
    }
    while ( tempNum >= 1 ){ // tempNum is <5 rn
        tempNum -= 1;
        std::cout << this->one; // 'IV' = 4
    }
    std::cout << std::endl;
}