//
//  Time.cpp
//  Date
//
//  Created by Oleksii Kyrylchuk on 10/25/15.
//  Copyright © 2015 olety. All rights reserved.
//
/*In the Gregorian calendar, a normal year consists of 365 days. Because the actual length of a sidereal year (the time required for the Earth to revolve once about the Sun) is actually 365.25635 days, a "leap year" of 366 days is used once every four years to eliminate the error caused by three normal (but short) years. Any year that is evenly divisible by 4 is a leap year: for example, 1988, 1992, and 1996 are leap years.
 
 However, there is still a small error that must be accounted for. To eliminate this error, the Gregorian calendar stipulates that a year that is evenly divisible by 100 (for example, 1900) is a leap year only if it is also evenly divisible by 400.
 
 For this reason, the following years are not leap years:
 1700, 1800, 1900, 2100, 2200, 2300, 2500, 2600
 This is because they are evenly divisible by 100 but not by 400.
 
 The following years are leap years:
 1600, 2000, 2400
 This is because they are evenly divisible by both 100 and 400. */
#include "Time.hpp"

float max ( float a, float b ){
    return (a>b)?a:b;
}

float min ( float a, float b ){
    return (a<b)?a:b;
}

float bound ( float val, float low, float high ){
    return (val>=low?(val<=high?val:high):low);
}

float abs ( float val ){
    return (val<0)?-val:val;
}

Time::Time(){
    this->nullify();
}

Time::Time ( float sec, float mins, float hrs, float days, float months, float years ){
    this->times[0] = sec;
    this->times[1] = mins;
    this->times[2] = hrs;
    this->times[3] = days;
    this->times[4] = months;
    this->times[5] = years;
}

void Time::nullify(){
    for ( int i = 0; i < 6; i++ ){
        this->times[i] = 0;
    }
}

float Time::getVar(int number){
    if ( number <0 || number > 5 ){
        std::cerr << "Wrong Time::getVar method usage" << std::endl
        << "Proper usage : getVar(int number), number = 0..5" << std::endl
        << "0 = sec, 1 = mins, 2 = hrs, 3 = days, 4 = months, 5 = years" << std::endl;
    }
    return this->times[number];
//    return (number>=0? (number<6?this->times[number]:-1) :-1);
}

void Time::setVar(int number, float value){
    if ( number <0 || number > 5 ){
        std::cerr << "Wrong Time::setVar method usage" << std::endl
        << "Proper usage : setVar(int number, float value), number = 0..5" << std::endl
        << "0 = sec, 1 = mins, 2 = hrs, 3 = days, 4 = months, 5 = years" << std::endl;
    } else if ( number < 2 ){
        bound(value, 0, 59 );
    } else if ( number == 2 ){
        bound (value, 0, 23 );
    } else if ( number == 3 ){
        bound (value, 1, 31);
    } else if ( number == 4 ){
        bound(value, 1, 12);
    }
    this->times[number] = value;
}

void Time::setAll(float sec, float mins, float hrs, float days, float months, float years ){
    this->times[0] = bound(sec,0,59);
    this->times[1] = bound(mins,0,59);
    this->times[2] = bound(hrs,0,23);
    this->times[3] = bound(days,1,31);
    this->times[4] = bound(months,1,12);
    this->times[5] = years;
}

float Time::numLeapYears(){
    float years = this->times[5];
    if ( this->times[4] < 2 ){ // Chack if we need to consider this year as a leap one
        years--;
    }
    years = truncf(this->times[5]/4) - truncf(this->times[5]/100) + truncf(this->times[5]/400);
    return years;
}

float Time::numYears ( Time time2 ){
    return abs(time2.getVar(5) - this->times[5]);
}

float Time::numMonths (){
    float months = this->times[4] + this->times[5]*12.0f;
    return months;
}

float Time::numMonths ( Time time2 ){
    return abs(this->numMonths() - time2.numMonths());
}

float Time::numDays (){
    float days = this->times[3] + this->times[5]*365;
    days += this->numLeapYears();
    for ( int i = 0; i < this->times[4]-1; i++){ // -1 because we've already accounted for this months days
        days += this->monthDays[i];
    }
    return days;
}

float Time::numDays( Time time2 ){
    return abs(this->numDays() - time2.numDays());
}

float Time::numHours(){
    return (this->numDays()*24.0f);
}

float Time::numHours( Time time2 ){
    return (this->numDays(time2)*24.0f);
}

void Time::print (){
    std::cout << this->times[2] << ":"
              << this->times[1] << ":"
              << this->times[0] << " "
              << this->times[3] << "/"
              << this->times[4] << "/"
              << this->times[5] << " ";
    
}

void Time::print ( bool secMinsHrs, bool daysMoYrs){
    if ( secMinsHrs && daysMoYrs )
        this->print();
    
    if ( secMinsHrs ){
        std::cout << this->times[2] << ":"
                  << this->times[1] << ":"
                  << this->times[0];
    }
    
    std::cout << this->times[3] << "/"
              << this->times[4] << "/"
              << this->times[5];
}
