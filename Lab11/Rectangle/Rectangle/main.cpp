//
//  main.cpp
//  Rectangle
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include "RectParallelepiped.hpp"

int main(void) {
    Rectangle rect(5,10); // [5,10] area = 50, diag ~ 11.2
    RectParallelepiped pip(7.5,10,10); // [5,10,10] area =400; diag. = 15
    rect.printArea();
    rect.printDiagonal();
    pip.printArea();
    pip.printDiagonal();
    return 0;
}
