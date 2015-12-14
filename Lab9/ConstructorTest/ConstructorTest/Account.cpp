//
//  Account.cpp
//  ConstructorTest
//
//  Created by Oleksii Kyrylchuk on 12/7/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "Account.hpp"

Account::Account(){
    std::cout << "Constructor called" << std::endl;
}
Account::~Account(){
    std::cout << "Destructor called" << std::endl;
}