//
//  Student.cpp
//  StudentMark
//
//  Created by Oleksii Kyrylchuk on 12/7/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "Student.hpp"


Student::Student(int mark, int ssn){
    this->mark = mark;
    this->ssn = ssn;
}

Student::~Student(){
    std::cout << "Destructor" << std::endl;
};

int Student::getMark(){
    return this->mark;
}

void Student::setMark(int mark){
    this->mark = mark;
}

int Student::getSsn(){
    return this->ssn;
}

void Student::setSsn(int ssn){
    this->ssn = ssn;
}