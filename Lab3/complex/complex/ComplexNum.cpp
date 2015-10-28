//
//  ComplexNum.cpp
//  complex
//
//  Created by Oleksii Kyrylchuk on 10/25/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "ComplexNum.hpp"
/*Implement a class of complex numbers. 
 The class should provide at least the implementation of the following operations: 
 - addition
 - subtraction
 - multiplication
 - division.
 Write a program illustrating the above operations.
 */

ComplexNum::ComplexNum(){
    this->real = 0.0;
    this->im = 0.0;
}

ComplexNum::ComplexNum( float real ){
    this->real = real;
    this->im = 0.0;
}

ComplexNum::ComplexNum( float real, float im ){
    this->real = real;
    this->im = im;
}

void ComplexNum::setReal(float real){
    this->real = real;
}

void ComplexNum::setIm(float im){
    this->im = im;
}

float ComplexNum::getReal(){
    return this->real;
}

float ComplexNum::getIm(){
    return this->im;
}

ComplexNum ComplexNum::operator=(ComplexNum eq){
    this->real = eq.real;
    this->im = eq.im;
    return *this;
}

void ComplexNum::printNum(){
    // Float outputs "-" by default it im < 0
    std::cout << this->real << ((this->im>0)?"+":"") << this->im << "i";
}

void ComplexNum::printNum( bool endl ){
    // Float outputs "-" by default it im < 0
    std::cout << this->real << ((this->im>0)?"+":"") << this->im << "i";
    if ( endl ){
        std::cout << std::endl;
    }
}

void ComplexNum::printNum(bool real, bool im, bool endl){
    if ( real && im ){
        this->printNum(endl);
    }
    // At least 1 part of a number is missing, so no need in a sign
    std::cout << (real? std::to_string(this->real) : "")
                << (im? std::to_string(this->im) : "")
                << (endl? "\n" : "");
}

ComplexNum operator + ( ComplexNum number1, ComplexNum number2 ){
    return ComplexNum(number1.real+number2.real, number1.im+number2.im);
}

ComplexNum operator - ( ComplexNum minuend, ComplexNum substraend ){
    return ComplexNum(minuend.real-substraend.real, minuend.im-substraend.im);
}

ComplexNum operator * ( ComplexNum number1, ComplexNum number2 ){
    return ComplexNum(number1.real*number2.real-number1.im*number2.im, number1.real*number2.im+number1.im*number2.real);
}

ComplexNum operator / ( ComplexNum dividend, ComplexNum divisor ){
    return ComplexNum((dividend.real*divisor.real+dividend.im*divisor.im)/(divisor.real*divisor.real+divisor.im*divisor.im),
                      (dividend.im*divisor.real-dividend.real*divisor.im)/(divisor.real*divisor.real+divisor.im*divisor.im));
}

std::ostream& operator <<(std::ostream &os, const ComplexNum &num){
    // Float outputs "-" by default it im < 0
    os << num.real << ((num.im>=0)?"+":"") << num.im << "i";
    return os;
}
