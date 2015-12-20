//
//  Rectangle.hpp
//  Rectangle
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <iostream>
#include <vector>
#include "Exception.hpp"
#include <math.h>

class Rectangle {
public:
    Rectangle();
    Rectangle( float x, float y );
    ~Rectangle();
    float getDiagonal();
    float getArea();
    void printDiagonal();
    void printArea();
    float getAttrib( int attribNum );
    void setAttrib( int attribNum, float value );
protected:
    std::vector<float> attributes;
};

#endif /* Rectangle_hpp */
