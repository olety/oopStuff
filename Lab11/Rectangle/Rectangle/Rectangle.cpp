//
//  Rectangle.cpp
//  Rectangle
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "Rectangle.hpp"


Rectangle::Rectangle(){
    Rectangle(1,1);
}

Rectangle::Rectangle( float x, float y ){
    this->attributes.resize(2);
    try{
        this->setAttrib(0, x);
        this->setAttrib(1, y);
    } catch ( Exception ex ){
        ex.printException();
    }
}

Rectangle::~Rectangle(){
    this->attributes.resize(0);
}

float Rectangle::getDiagonal(){
    return sqrtf(pow(getAttrib(0), 2)+pow(getAttrib(1), 2));
}

float Rectangle::getArea(){
    return getAttrib(0)*getAttrib(1);
}

void Rectangle::printDiagonal(){
    std::cout << "Diagonal of a rect [" << this->getAttrib(0) << "," << this->getAttrib(1) << "]"
              << " equals " << this->getDiagonal() << std::endl;
}

void Rectangle::printArea(){
    std::cout << "Area of a rect [" << this->getAttrib(0) << "," << this->getAttrib(1) << "]"
    << " equals " << this->getArea() << std::endl;
}

float Rectangle::getAttrib( int attribNum ){
    if ( attribNum >= this->attributes.size() ){
        throw Exception(1);
    }
    return this->attributes[attribNum];
}

void Rectangle::setAttrib( int attribNum, float value ){
    if ( value <= 0 ){
        throw Exception(0);
    } else if ( attribNum >= this->attributes.size() ){
        throw Exception(1);
    }
    
    this->attributes[attribNum] = value;
}
