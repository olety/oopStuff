//
//  matrix.hpp
//  matrixMult
//
//  Created by Oleksii Kyrylchuk on 10/5/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <iostream>
#include <vector>

class Matrix{
public:
    Matrix( int rows, int cols);
    ~Matrix();
    Matrix *createMult ( Matrix *two );
    void fillMatrix(); // uses cout now
    void print();
    int getRows ();
    int getCols ();
private:
    void nullify();
    int rows, cols;
protected:
    std::vector<std::vector<double> > matrix;
};

#endif /* matrix_hpp */
