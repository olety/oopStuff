/*
 Implement in C language an algorithm for matrix multiplication.

 Use dynamic data structures for both arguments and result – program should ask the user about sizes of both input arrays, check if the multiplication can be performed, then allocate memory space for input arrays and output one before performing the calculations.

 Classic malloc() function and pointers should be enough.

 Free memory after displaying result and ask about new input or exit from
    program.
 */

#include <iostream>
#include <stdio.h>
#include "matrix.hpp"


int main(int argc, const char * argv[]) {
    Matrix *m1, *m2, *m3;
    int rows1, cols1, rows2, cols2;
    std::cout << "Matrix 1 rows cols: \n";
    std::cin >> rows1 >> cols1;
    std::cout << "Matrix 2 rows cols: \n";
    std::cin >> rows2 >> cols2;
    m1 = new Matrix(rows1, cols1);
    m1->fillMatrix();
//    m1->print();
    std::cout << "Input matrix 2 \n";
    m2 = new Matrix(rows2, cols2);
    m2->fillMatrix();
//    m1->print();
    if ( (m3 = m1->createMult(m2)) == nullptr ){
        std::cout << "Couldn't multiply matrices";
        exit (EXIT_FAILURE);
    }
    m3->print();
    return 0;
}
