//
//  main.cpp
//  sales
//
//  Created by Oleksii Kyrylchuk on 10/19/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "analyzer.hpp"

int main(int argc, const char * argv[]) {
    std::ifstream in;
    std::ofstream out;
    in.open("in.txt");
    out.open ("out.txt");
    if ( !in.is_open() || !out.is_open()){
        return -1;
    }
    Analyzer *analyze = new Analyzer(&in);
    analyze->printMatrix();
    analyze->printTotProduct(2, &out);
    analyze->printTotal( &out );
    return 0;
}
