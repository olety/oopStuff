//
//  RectParallelepiped.hpp
//  Rectangle
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef RectParallelepiped_hpp
#define RectParallelepiped_hpp

#include "Rectangle.hpp"

class RectParallelepiped : public Rectangle {
public:
    RectParallelepiped();
    RectParallelepiped( float x, float y, float h );
    float getDiagonal();
    void printDiagonal();
    float getArea();
    void printArea();
};

#endif /* RectParallelepiped_hpp */
