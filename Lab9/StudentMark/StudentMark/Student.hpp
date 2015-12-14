//
//  Student.hpp
//  StudentMark
//
//  Created by Oleksii Kyrylchuk on 12/7/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <iostream>

class Student {
private:
    int mark, ssn;
public:
    Student(int mark = 0, int ssn = 0);
    ~Student();
    int getMark();
    void setMark(int mark);
    int getSsn();
    void setSsn(int ssn);
};

#endif /* Student_hpp */
