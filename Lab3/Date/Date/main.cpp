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
    Time time1, time2;
    time1.setAll(1, 2, 3, 4, 5, 2015);
    time2.setAll(9, 12, 23, 30, 3, 2011);
    time1.print();
    std::cout << std::endl;
    time2.print();
    std::cout << std::endl;
    std::cout << "Years : " << time1.numYears(time2);
    std::cout << std::endl;
    std::cout << "Months : " << time1.numMonths(time2);
    std::cout << std::endl;
    std::cout << "Days : " << time1.numDays(time2);
    std::cout << std::endl;
    std::cout << "Hours : " << time1.numHours(time2);
    std::cout << std::endl;
    return 0;
}
