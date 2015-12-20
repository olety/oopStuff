//
//  main.cpp
//  StudentClass
//
//  Created by Oleksii Kyrylchuk on 12/14/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include "Student.hpp"

int main(void) {
    Student *newStud = new Student("","Last", 0, -1);
//    newStud->printData(); //wont show anything abyway
    newStud->setData("First", "Last", -1, 1997);
    newStud->setData("First", "Last", 12, 1997);
    newStud->printData();
    return 0;
}
