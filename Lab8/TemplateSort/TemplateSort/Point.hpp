//
//  Point.hpp
//  TemplateSort
//
//  Created by Oleksii Kyrylchuk on 12/7/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <iostream>

class Point{
public:
    int x, y;
    bool xMain;
    Point(int x = 0, int y = 0, bool xMain = true);
//    void setXMain (bool val);
    void print();
    bool operator > ( Point second ) const;
    bool operator < ( Point second ) const;
};

#endif /* Point_hpp */
