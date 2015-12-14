//
//  Student.cpp
//  StudentClass
//
//  Created by Oleksii Kyrylchuk on 12/14/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "Student.hpp"

void fNameEmptyException::printException(){
    std::cerr << "Student first name is empty!" << std::endl;
}

void studIdWrongException::printException(){
    std::cerr << "Student id name is incorrect!" << std::endl;
}


Student::Student(std::string firstName, std::string lastName, int studentId, int year){
    this->setData(firstName, lastName, studentId, year);
}

void Student::setData(std::string firstName, std::string lastName, int studentId, int year){
    try {
        this->setFName(firstName);
        this->setStudId(studentId);
        this->yearOfStudy = year;
        this->lName = lastName;
    } catch (fNameEmptyException ex){
        ex.printException();
    } catch ( studIdWrongException ex ){
        ex.printException();
    }
}

void Student::setFName(std::string firstName){
    if ( firstName != "" ){
        this->fName = firstName;
    } else {
        throw fNameEmptyException();
    }
}

void Student::setStudId(int studentId){
    if ( studentId > 0 ){
        this->studId = studentId;
    } else {
        throw studIdWrongException();
    }
}

void Student::printData(){
    std::cout << "Name : " << this->fName << " " << this->lName  << std::endl
              << " Id : " << this->studId << " Year : " << this->yearOfStudy << std::endl;
}