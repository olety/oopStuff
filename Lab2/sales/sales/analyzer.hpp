//
//  Analyzer.hpp
//  sales
//
//  Created by Oleksii Kyrylchuk on 10/19/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef analyzer_hpp
#define analyzer_hpp

#include <iostream>
#include <fstream>
#include <vector>

class Analyzer {
public:
    Analyzer();
    Analyzer(std::ifstream *in);
    ~Analyzer();
    float getTotProduct ( float prodNo );
    float getTotPerson ( float personNo );
    float getTotPersonProduct ( float personNo, float prodNo );
    void printMatrix();
    void printTotPerson ( float personNo, std::ofstream *stream );
    void printTotProduct ( float prodNo, std::ofstream *stream );
    void printTotPerson ( float personNo );
    void printTotProduct ( float prodNo );
    void analyzeTotal();
    void printTotal(std::ofstream *stream);
    void printTotal();
private:
    std::vector<std::vector<float>> inMatrix;
    std::vector<std::vector<float>> outMatrix;
};

#endif /* Analyzer_hpp */
