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
#include <math.h>  

class Time{
public:
    Time();
    Time ( float sec, float mins, float hrs, float days, float months, float years );
    float getVar(int number); // 0 = sec, 1 = mins, 2 = hrs, 3 = days, 4 = months, 5 = years;
    void setVar(int number, float value);
    void setAll ( float sec, float mins, float hrs, float days, float months, float years );
    void nullify();
    float numLeapYears();
    float numHours();
    float numDays ();
    float numMonths ();
    float numHours ( Time time2 );
    float numDays( Time time2 );
    float numMonths ( Time time2 );
    float numYears ( Time time2 );
    void print ();
    void print ( bool secMinsHrs, bool daysMoYrs);
private:
    float times[6];
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};
};

float max ( float a, float b );
float min ( float a, float b );
float bound ( float val, float low, float high );
float abs ( float val );
#endif /* Time_hpp */
