//
//  Point.cpp
//  TemplateSort
//
//  Created by Oleksii Kyrylchuk on 12/7/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "Point.hpp"

Point::Point(int x, int y, bool xMain){
    this->x = x;
    this->y = y;
    this->xMain = xMain;
}

//void Point::setXMain(bool val){
//    this->xMain = val;
//}

void Point::print(){
    std::cout << "x : " << x << " y : " << y << std::endl;
}

bool Point::operator >(Point second) const {
    if ( xMain && second.xMain ){
        return x>second.x?true:false;
    } else {
        return y>second.y?true:false;
    }
}

bool Point::operator < (Point second) const {
    if ( xMain && second.xMain ){
        return x<second.x?true:false;
    } else {
        return y<second.y?true:false;
    }
}