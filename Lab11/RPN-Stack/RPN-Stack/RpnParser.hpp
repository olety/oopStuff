//
//  RpnParser.hpp
//  RPN-Stack
//
//  Created by Oleksii Kyrylchuk on 12/20/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef RpnParser_hpp
#define RpnParser_hpp

#include <iostream>
#include <sstream>
#include "GenericStack.hpp"
#include "Exception.hpp"

template <typename T>
class RpnParser{
public:
    RpnParser( GenericStack<T> stack, bool debugMode = false );
    void setDebugMode( bool debugMode );
    T parse ( std::string string );
private:
    GenericStack<T> stack;
    bool debugMode = false;
};

#include "RpnParser.cpp"
#endif /* RpnParser_hpp */
