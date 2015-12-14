//
//  main.cpp
//  StudentMark
//
//  Created by Oleksii Kyrylchuk on 12/7/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Student.hpp"

float getAverage ( std::vector<Student*> studArr ){
    if ( studArr.size() == 0 ){
        std::cerr << "Can't divide by zero!" << std::endl;
//        exit(EXIT_FAILURE);
        return -1.0f;
    }
    float avg = 0;
    for ( int i = 0; i < studArr.size(); i++ ){
        avg += studArr[i]->getMark();
    }
    avg /= studArr.size();
    return avg;
}

int main(void) {
    std::vector<Student*> studArr;
    int size;
    std::cout << "Student array size : " << std::endl;
    std::cin >> size;
    studArr.resize(size);
    for ( int i = 1; i <= size; i++ ){
        studArr[i-1] = new Student(i,i);
    }
    
    std::cout << "Average mark : " << getAverage(studArr) << std::endl;
    
    for ( int i = 0; i < size; i++ ){
        delete studArr[i];
    }
    return 0;
}
