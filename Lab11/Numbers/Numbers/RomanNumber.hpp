//
//  RomanNumber.hpp
//  Numbers
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef RomanNumber_hpp
#define RomanNumber_hpp

#include "ArabianNumber.hpp"
#include "Exception.hpp"

class RomanNumber : public ArabianNumber {
protected:
    static const char thousand = 'M';
    static const char fiveHundred = 'D';
    static const char hundred = 'C';
    static const char fifty = 'L';
    static const char ten = 'X';
    static const char five = 'V';
    static const char one = 'I';
public:
    RomanNumber(int number);
    void print();
};

#endif /* RomanNumber_hpp */
