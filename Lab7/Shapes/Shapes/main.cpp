//
//  main.cpp
//  Shapes
//
//  Created by Oleksii Kyrylchuk on 11/23/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include "Shapes.hpp"
int main(int argc, const char * argv[]) {
    Rect r("Rect1", 0, 0, 10, 20);
    r.printMeasures();
    Square s("Square1", 0, 0, 15);
    s.printMeasures();
    Circle c("Circle1", 0, 0, 20);
    c.printMeasures();
    return 0;
}
