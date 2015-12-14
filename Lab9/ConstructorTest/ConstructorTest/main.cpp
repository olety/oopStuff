//
//  main.cpp
//  ConstructorTest
//
//  Created by Oleksii Kyrylchuk on 12/7/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include "Account.hpp"

int main(int argc, const char * argv[]) {
    Account *acc = new Account();
    delete acc; // comment this line and destructor won't be called.
    return 0;
}
