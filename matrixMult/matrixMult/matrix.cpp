//
//  matrix.cpp
//  matrixMult
//
//  Created by Oleksii Kyrylchuk on 10/5/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "matrix.hpp"


Matrix :: Matrix(int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    this->matrix.resize((size_t) rows);
    for ( int i = 0; i < rows; i++ ){
        this->matrix[i].resize((size_t) cols);
    }
    this->nullify();
}


Matrix::~Matrix(){
//    for ( int i = 0; i < this->rows;)
}

void Matrix::fillMatrix(){
    for ( int i = 0; i < this->rows; i++){
        std::cout << "Matrix row #" << (i+1) << std::endl;
        for ( int j = 0; j < this->cols; j++){
            std::cin >> matrix[i][j];
        }
    }
}

Matrix *Matrix::createMult(Matrix *two){
    if ( this->getCols() != two->getRows() )
        return nullptr;
    
    Matrix *product = new Matrix(this->getRows(), two->getCols());
    
    for ( int i = 0; i < product->rows; i++){
        for( int j = 0; j < product->cols; j++){
            for ( int k = 0; k < this->cols; k++){
                product->matrix[i][j] += this->matrix[i][k]*two->matrix[k][j];
            }
        }
    }
    
    
    return product;
}

void Matrix::nullify(){
    for ( int i = 0; i < this->rows; i++)
        for ( int j = 0; j < this->rows; j++)
            this->matrix[i][j] = 0;
}

void Matrix::print(){
    for ( int i = 0; i < this->rows; i++){
        for ( int j = 0; j < this->cols; j++){
            std::cout << this->matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int Matrix::getRows(){
    return this->rows;
}

int Matrix::getCols(){
    return this->cols;
}