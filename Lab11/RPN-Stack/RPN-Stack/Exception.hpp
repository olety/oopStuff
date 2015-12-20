//
//  Exception.hpp
//  RPN-Stack
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Exception_hpp
#define Exception_hpp

#include <iostream>

class Exception{
public:
    Exception( int numException = 0 );
    void printException();
    int getNum();
private:
    int numException;
};

#endif /* Exception_hpp */
