//
//  Time.hpp
//  Date
//
//  Created by Oleksii Kyrylchuk on 10/25/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <iostream>
#include <iomanip>
#include <math.h>

class Time{
public:
    Time();
    Time ( int sec, int mins, int hrs );
    int getVar(int number); // 0 = sec, 1 = mins, 2 = hrs
    void setVar(int number, int value);
    void setAll ( int sec, int mins, int hrs );
    void nullify();
    friend Time operator - (Time time1, Time time2 );
    friend Time operator + (Time time1, Time time2 );
    friend std::ostream& operator << (std::ostream &os, const Time &time);
    friend std::istream& operator >> (std::istream &is, Time &time);
    void print ();
private:
    int times[3]; // 0 = sec, 1 = mins, 2 = hrs
};

int max ( int a, int b );
int min ( int a, int b );
int bound ( int val, int low, int high );
int overBound ( int val, int low, int high );
int overBound ( int val, int low, int high, int& carry);
int abs ( int val );
#endif /* Time_hpp */
