//
//  main.cpp
//  matrixMultNoOOP
//
//  Created by Oleksii Kyrylchuk on 10/6/15.
//  Copyright © 2015 olety. All rights reserved.
//
// how calculation is done : ( for clarification )
// Currow/curcol = current row/col of result, index_currow/col = index of it in the array
//int currow = (int) (i/product->cols);
//int index_currow = (int) k + currow*matrix1.cols;
//int curcol = (int) i - currow*(product->cols);
//int index_curcol = (int) curcol + k*(product->cols);
//*(product->matrix + i) += *(matrix1.matrix + index_currow) * *(matrix2.matrix + index_curcol);
//

#include <iostream>
#include <stdio.h>

struct Matrix{
    float* matrix;
    int rows, cols;
};

void fillMatrix( Matrix matrix){
    std::cout << "Input Matrix" << std::endl;
    for ( int i = 0; i < (matrix.rows*matrix.cols); i++){
        std::cin >> *(matrix.matrix+i);
    }
}

void zerofy( Matrix matrix ){
    for ( int i = 0; i < (matrix.rows*matrix.cols); i++)
            *(matrix.matrix+i) = 0;
}

void print( Matrix matrix ){
    for ( int i = 1; i <= matrix.rows*matrix.cols; i++){
        std::cout << *(matrix.matrix+i-1) << " ";
        if (i%matrix.cols == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

Matrix* multiply (Matrix matrix1, Matrix matrix2){
    if ( matrix1.cols != matrix2.rows){
        std::cout << "Could not multiply matrices.";
        return nullptr;
    }
    
    Matrix *product = new Matrix;
    product->matrix = new float[matrix1.rows*matrix2.cols];
    product->rows = matrix1.rows;
    product->cols = matrix2.cols;
    zerofy(*product);
    for ( int i = 0; i < (product->rows*product->cols); i++){
        for ( int k = 0; k < matrix1.cols; k++ ){
            *(product->matrix + i) += *(matrix1.matrix + k + (i/product->cols)*matrix1.cols) *
            *(matrix2.matrix + i - (i/product->cols)*(product->cols) + k*(product->cols));
        }
    }
    return product;
}

int main(int argc, const char * argv[]) {
    Matrix matrix1, matrix2, *matrix3;
    std::cout << "Matrix 1 rows cols: \n";
    std::cin >> matrix1.rows >> matrix1.cols;
    std::cout << "Matrix 2 rows cols: \n";
    std::cin >> matrix2.rows >> matrix2.cols;
    matrix1.matrix = new float[matrix1.rows*matrix1.cols];
    matrix2.matrix = new float[matrix1.rows*matrix1.cols];
    fillMatrix(matrix1);
    fillMatrix(matrix2);
    std::cout << "Matrix #1 : " << std::endl;
    print(matrix1);
    std::cout << "Matrix #2 : " << std::endl;
    print(matrix2);
    std::cout << "Product : " << std::endl;
    if ((matrix3 = multiply(matrix1, matrix2)) == nullptr ){
        exit(EXIT_FAILURE);
    }
    print(*matrix3);
    delete[] matrix1.matrix;
    delete[] matrix2.matrix;
    delete[] matrix3->matrix;
    delete[] matrix3;
    return 0;
}
