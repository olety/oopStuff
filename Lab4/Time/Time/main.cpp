//
//  main.cpp
//  Date
//
//  Created by Oleksii Kyrylchuk on 10/25/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include "Time.hpp"

int main(int argc, const char * argv[]) {
    Time time1, time2, time3;
    std::cin >> time1;
    time2.setAll(9, 12, 23);
    std::cout << "Time #1 : " << time1 << std::endl << "Time # 2 : " << time2 << std::endl;
    time3 = time1 - time2;
    std::cout << "Time 1 - Time 2 : " << time3 << std::endl;
    time3 = time2 - time1;
    std::cout << "Time 2 - Time 1 : " << time3 << std::endl;
    time3 = time1 + time2;
    std::cout << "Sum of them : " << time3 << std::endl; 
    return 0;
}
