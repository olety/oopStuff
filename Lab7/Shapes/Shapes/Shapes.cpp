//
//  Shapes.cpp
//  Shapes
//
//  Created by Oleksii Kyrylchuk on 11/23/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "Shapes.hpp"

// --------------------------------------------------------------------------------------------------------------------------
// SHAPE
// --------------------------------------------------------------------------------------------------------------------------

Shape::Shape( std::string name ){
    this->name = name;
};

void Shape::printName(){
    std::cout << "Shape name : " <<name << std::endl;
};

void Shape::setName( std::string name ){
    this->name = name;
};

// --------------------------------------------------------------------------------------------------------------------------
// SHAPE2D
// --------------------------------------------------------------------------------------------------------------------------

Shape2D::Shape2D ( std::string name, float startX, float startY ) : Shape(name){
    this->startX = startX;
    this->startY = startY;
};


float Shape2D::getArea(){
    return this->area;
};

void Shape2D::printArea(){
    std::cout << "Area of " << this->name << " : " << this->area << std::endl;
};

void Shape2D::setStartCoords( float startX, float startY ){
    this->startX = startX;
    this->startY = startY;
};

float Shape2D::getStartX(){
    return this->startX;
};

float Shape2D::getStartY(){
    return this->startY;
};

// --------------------------------------------------------------------------------------------------------------------------
// SHAPE3D
// --------------------------------------------------------------------------------------------------------------------------


Shape3D::Shape3D ( std::string name, float startX, float startY, float startZ ) : Shape2D(name, startX, startY){
    this->startZ = startZ;
};

float Shape3D::getVolume(){
    return this->volume;
};

void Shape3D::printVolume(){
    std::cout << "Volume of " << this->name << " : " << this->volume << std::endl;
};


// --------------------------------------------------------------------------------------------------------------------------
// SQUARE
// --------------------------------------------------------------------------------------------------------------------------

Square::Square( std::string name, float startX, float startY, float sideLen) : Shape2D(name, startX, startY){
    this->sideLen = sideLen;
    updateArea();
}

void Square::updateArea(){
    this->area = this->sideLen*this->sideLen;
};

void Square::setSideLen( float sideLen ){
    this->sideLen = sideLen;
};

float Square::getSideLen(){
    return this->sideLen;
};

void Square::printMeasures(){
    std::cout << "------------------------------" << std::endl;
    this->printName();
    std::cout << "Start coords : " << this->getStartX() << "X " << this->getStartY() << "Y"<< std::endl;
    std::cout << "Side length : " << this->sideLen << std::endl;
    this->printArea();
    std::cout << "------------------------------" << std::endl;
}

// --------------------------------------------------------------------------------------------------------------------------
// RECTANGLE
// --------------------------------------------------------------------------------------------------------------------------

Rect::Rect( std::string name, float startX, float startY, float width, float height) : Shape2D(name, startX, startY){
    this->width = width;
    this->height = height;
    updateArea();
};

void Rect::updateArea(){
    this->area = this->width*this->height;
};

void Rect::setWidth( float width ){
    this->width = width;
};

float Rect::getWidth(){
    return this->width;
};

void Rect::setHeight( float height ){
    this->height = height;
};

float Rect::getHeight(){
    return this->height;
};

void Rect::printMeasures(){
    std::cout << "------------------------------" << std::endl;
    this->printName();
    std::cout << "Start coords : " << this->getStartX() << "X " << this->getStartY() << "Y"<< std::endl;
    std::cout << "Width: " << this->width << std::endl << "Height : "  << this->height << std::endl;
    this->printArea();
    std::cout << "------------------------------" << std::endl;
}

// --------------------------------------------------------------------------------------------------------------------------
// CIRCLE
// --------------------------------------------------------------------------------------------------------------------------

Circle::Circle( std::string name, float startX, float startY, float radius) : Shape2D(name, startX, startY){
    this->radius = radius;
    updateArea();
};

void Circle::updateArea(){
    this->area = 3.14*this->radius*this->radius;
};

void Circle::setRadius( float radius ){
    this->radius = radius;
};

float Circle::getRadius(){
    return this->radius;
};

void Circle::printMeasures(){
    std::cout << "------------------------------" << std::endl;
    this->printName();
    std::cout << "Start coords : " << this->getStartX() << "X " << this->getStartY() << "Y"<< std::endl;
    std::cout << "Radius : " << this->radius << std::endl;
    this->printArea();
    std::cout << "------------------------------" << std::endl;
}
