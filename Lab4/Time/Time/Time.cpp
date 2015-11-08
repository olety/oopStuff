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

int max ( int a, int b ){
    return (a>b)?a:b;
}

int min ( int a, int b ){
    return (a<b)?a:b;
}

int bound ( int val, int low, int high ){
    return (val>=low?(val<=high?val:high):low);
}

int overBound ( int val, int low, int high){
    if ( val > high ){
        val = low + abs(val - high) - 1;
    } else if ( val < low ){
        val = high - abs(val - low) + 1;
    }
    return val;
}

int overBound ( int val, int low, int high, int& carry){
    if ( val > high ){
        val = low + abs(val - high) - 1;
        carry = 1;
    } else if ( val < low ){
        val = high - abs(val - low) + 1;
        carry = 1;
    } else {
        carry = 0;
    }
    return val;
}

int abs ( int val ){
    return (val<0)?-val:val;
}

Time::Time(){
    this->nullify();
}

Time::Time ( int sec, int mins, int hrs ){
    this->times[0] = sec;
    this->times[1] = mins;
    this->times[2] = hrs;
}

void Time::nullify(){
    for ( int i = 0; i < 3; i++ ){
        this->times[i] = 0;
    }
}

int Time::getVar(int number){
    if ( number <0 || number > 2 ){
        std::cerr << "Wrong Time::setVar method usage" << std::endl
        << "Proper usage : setVar(int number, int value), number = 0..2" << std::endl
        << "0 = sec, 1 = mins, 2 = hrs" << std::endl;
    }
    return this->times[number];
}

void Time::setVar(int number, int value){
    if ( number <0 || number > 2 ){
        std::cerr << "Wrong Time::setVar method usage" << std::endl
        << "Proper usage : setVar(int number, int value), number = 0..2" << std::endl
        << "0 = sec, 1 = mins, 2 = hrs" << std::endl;
    } else if ( number < 2 ){
        bound(value, 0, 59 );
    } else if ( number == 2 ){
        bound (value, 0, 23 );
    }
}

void Time::setAll(int sec, int mins, int hrs){
    this->times[0] = bound(sec,0,59);
    this->times[1] = bound(mins,0,59);
    this->times[2] = bound(hrs,0,23);
}


void Time::print (){
    std::cout << this->times[2] << ":"
              << this->times[1] << ":"
              << this->times[0] << " ";
}


std::ostream& operator <<(std::ostream &os, const Time &time){
    os << std::setw(2) << std::setfill('0') << time.times[2] << ":"
    << std::setw(2) << std::setfill('0') << time.times[1] << ":"
    << std::setw(2) << std::setfill('0') << time.times[0] << " ";
    return os;
}


std::istream& operator >> (std::istream &is, Time &time){
    int a[3];
    is >> a[2] >> a[1] >> a[0];
    time.setAll(a[0], a[1], a[2]);
    return is;
}

Time operator - (Time time1, Time time2){
    int carry = 0;
    int numSec = overBound(time1.getVar(0)-time2.getVar(0), 0, 59, carry);
    int numMin = overBound(time1.getVar(1)-time2.getVar(1)-carry, 0, 59, carry);
    int numHrs = overBound(time1.getVar(2)-time2.getVar(2)-carry, 0, 23);
    return Time(numSec, numMin, numHrs);
}

Time operator + (Time time1, Time time2){
    int carry = 0;
    int numSec = overBound(time1.getVar(0)+time2.getVar(0), 0, 59, carry);
    int numMin = overBound(time1.getVar(1)+time2.getVar(1)+carry, 0, 59, carry);
    int numHrs = overBound(time1.getVar(2)+time2.getVar(2)+carry, 0, 23);
    return Time(numSec, numMin, numHrs);
}
