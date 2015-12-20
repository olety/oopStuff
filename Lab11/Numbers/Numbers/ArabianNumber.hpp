//
//  ArabianNumber.hpp
//  Numbers
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef ArabianNumber_hpp
#define ArabianNumber_hpp

#include <iostream>
#include "Exception.hpp"
class ArabianNumber{
public:
    ArabianNumber(int number = 0);
    void print();
protected:
    int number;
};

#endif /* ArabianNumber_hpp */
