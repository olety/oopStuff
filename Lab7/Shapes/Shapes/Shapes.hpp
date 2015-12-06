//
//  Shapes.hpp
//  Shapes
//
//  Created by Oleksii Kyrylchuk on 11/23/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Shapes_hpp
#define Shapes_hpp

#include <iostream>
class Shape{
public:
    Shape( std::string name );
    virtual void printName();
    virtual void setName( std::string name );
    virtual void printMeasures() = 0;
protected:
    std::string name;
};

class Shape2D : public Shape {
public:
    Shape2D ( std::string name, float startX, float startY );
    virtual float getArea();
    virtual void updateArea() = 0;
    virtual void printArea();
    void setStartCoords( float startX, float startY );
    float getStartX();
    float getStartY();
protected:
    float area, startX, startY;
};

class Shape3D : public Shape2D {
public:
    Shape3D ( std::string name, float startX, float startY, float startZ );
    virtual float getVolume();
    virtual void updateVolume() = 0;
    virtual void printVolume();
protected:
    float volume, startZ;
};

class Square : public Shape2D{
public:
    Square( std::string name = "Square", float startX = 0, float startY = 0, float sideLen = 0);
    void updateArea();
    void printMeasures();
    void setSideLen( float sideLen );
    float getSideLen();
protected:
    float sideLen;
};


class Rect : public Shape2D{
public:
    Rect( std::string name = "Rect", float startX = 0, float startY = 0, float width = 1, float height = 1);
    void updateArea();
    void printMeasures();
    void setWidth( float width );
    float getWidth();
    void setHeight( float height );
    float getHeight();
protected:
    float width, height;
};

class Circle : public Shape2D{
public:
    Circle( std::string name = "Circle", float startX = 0, float startY = 0, float radius = 1);
    void updateArea();
    void printMeasures();
    void setRadius( float radius );
    float getRadius();
protected:
    float radius;
};
#endif /* Shapes_hpp */
