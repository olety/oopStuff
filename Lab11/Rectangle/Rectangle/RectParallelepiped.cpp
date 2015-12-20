//
//  RectParallelepiped.cpp
//  Rectangle
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "RectParallelepiped.hpp"

RectParallelepiped::RectParallelepiped():Rectangle(){
    RectParallelepiped(1,1,1);
}

RectParallelepiped::RectParallelepiped( float x, float y, float h ):Rectangle(x,y){
    this->attributes.resize(3);
    try{
        this->setAttrib(2, h);
    } catch (Exception ex){
        ex.printException();
    }
}

float RectParallelepiped::getArea(){
    float a = getAttrib(0);
    float b = getAttrib(1);
    float h = getAttrib(2);
    return (2*a*b)+(2*a*h)+(2*b*h);
}

float RectParallelepiped::getDiagonal(){
    float a2 = pow(getAttrib(0),2);
    float b2 = pow(getAttrib(1),2);
    float h2 = pow(getAttrib(2),2);
    return sqrtf(a2+b2+h2);
}

void RectParallelepiped::printArea(){
    std::cout << "Area of a rectangular parallelepiped [" << this->getAttrib(0)
    << "," << this->getAttrib(1) << "," << this->getAttrib(2) << "]"
    << " equals " << this->getArea() << std::endl;
}

void RectParallelepiped::printDiagonal(){
    std::cout << "Diagonal of a rectangular parallelepiped [" << this->getAttrib(0)
              << "," << this->getAttrib(1) << "," << this->getAttrib(2) << "]"
              << " equals " << this->getDiagonal() << std::endl;
}