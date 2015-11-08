//
//  ComplexNum.hpp
//  complex
//
//  Created by Oleksii Kyrylchuk on 10/25/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef ComplexNum_hpp
#define ComplexNum_hpp
#include <iostream>
class ComplexNum {
public:
    ComplexNum ();
    ComplexNum ( float real );
    ComplexNum ( float real, float im );
    void setReal( float real );
    void setIm( float im );
    float getReal (); // No pun intended :)
    float getIm ();
    ComplexNum operator = ( ComplexNum eq );
    friend ComplexNum operator + ( ComplexNum number1, ComplexNum number2 );
    friend ComplexNum operator - ( ComplexNum minuend, ComplexNum substraend );
    friend ComplexNum operator * ( ComplexNum number1, ComplexNum number2 );
    friend ComplexNum operator / ( ComplexNum dividend, ComplexNum divisor );
    friend std::ostream& operator <<(std::ostream &os, const ComplexNum &num);
    friend std::istream& operator >> (std::istream &is, ComplexNum &num);
    void printNum ();
    void printNum ( bool endl );
    void printNum ( bool real, bool im, bool endl);
private:
    float real, im;
};
#endif /* ComplexNum_hpp */
