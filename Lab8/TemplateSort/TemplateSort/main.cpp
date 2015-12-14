//
//  main.cpp
//  TemplateSort
//
//  Created by Oleksii Kyrylchuk on 12/7/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.hpp"
//
//template <typename T>
//T sort(T first, T second, char oper){
//    switch (oper){
//        case '>' :
//            return first>second?first:second;
//            break;
//        case '<' :
//            return first<second?first:second;
//            break;
//        default :
//            return NULL;
//    }
//}

int main(int argc, const char * argv[]) {
    std::vector<Point> arr;
    int size;
    std::cout << "Say arr size : " << std::endl;
    std::cin >> size;
    arr.resize(size);
    for ( int i = 0; i < size; i++){
        arr[i] = Point(size-i,i,true);
    }
    for ( int i = 0; i < size; i++){
        arr[i].print();
    }
    std::cout << "X-sorted : " << std::endl;
    std::sort(arr.begin(), arr.end());
//    std::sort(arr.begin(), arr.end(), [](Point a, Point b) {
//        return b < a;
//    });
    
    for ( int i = 0; i < size; i++){
        arr[i].print();
        arr[i].xMain = false;
    }
   
    std::cout << "Y-sorted : " << std::endl;
    std::sort(arr.begin(), arr.end());
    for ( int i = 0; i < size; i++){
        arr[i].print();
    }
    
    return 0;
}
