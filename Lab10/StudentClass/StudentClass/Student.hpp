//
//  Student.hpp
//  StudentClass
//
//  Created by Oleksii Kyrylchuk on 12/14/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <iostream>

class fNameEmptyException{
public:
    void printException();
};

class studIdWrongException{
public:
    void printException();
};

class Student {
public:
    Student(std::string firstName, std::string lastName, int studentId, int year);
    void setData(std::string firstName, std::string lastName, int studentId, int year);
    void printData();
    void setStudId( int studId );
    void setFName ( std::string fName );
private:
    std::string fName;
    std::string lName;
    int studId;
    int yearOfStudy;

};

#endif /* Student_hpp */
