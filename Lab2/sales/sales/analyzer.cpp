//
//  analyzer.cpp
//  sales
//
//  Created by Oleksii Kyrylchuk on 10/19/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "analyzer.hpp"



analyzer::analyzer(){
    int i=0,j;
    std::string line;
    while(1){
        this->inMatrix.resize(this->inMatrix.size()+1);
        this->inMatrix[i].resize(3);
        for ( j = 0; j < 3; j++){
            if ( !(std::cin >> this->inMatrix[i][j]) ){
                this->inMatrix.erase(this->inMatrix.begin()+i);
                return;
            }
            if ( this->inMatrix[i][j] < 0 || ((j==0)&&(this->inMatrix[i][j]>4)) || ((j==1)&&(this->inMatrix[i][j]>5))){
                this->inMatrix.erase(this->inMatrix.begin()+i);
                return;
            }
        }
        i++;
    }
}

analyzer::analyzer( std::ifstream *in ){
    int i=0,j;
    std::string line;
    while(1){
        this->inMatrix.resize(this->inMatrix.size()+1);
        this->inMatrix[i].resize(3);
        for ( j = 0; j < 3; j++){
            if ( !(*in >> this->inMatrix[i][j]) ){
                this->inMatrix.erase(this->inMatrix.begin()+i);
                return;
            }
            if ( this->inMatrix[i][j] < 0 || ((j==0)&&(this->inMatrix[i][j]>4)) || ((j==1)&&(this->inMatrix[i][j]>5))){
                this->inMatrix.erase(this->inMatrix.begin()+i);
                return;
            }
        }
        i++;
    }
}

analyzer::~analyzer(){
    for ( int i = 0; i < this->inMatrix.size(); i++ ){
        this->inMatrix[i].erase(this->inMatrix[i].begin(), this->inMatrix[i].end());
    }
    this->inMatrix.erase(this->inMatrix.begin(), this->inMatrix.end());
}


float analyzer::getTotPerson(float personNo){
    float sum = 0;
    for ( int i = 0; i < this->inMatrix.size(); i++){
        if(this->inMatrix[i][0] == personNo ){
            sum += this->inMatrix[i][2];
        }
    }
    return sum;
}

float analyzer::getTotProduct(float prodNo){
    float sum = 0;
    for ( int i = 0; i < this->inMatrix.size(); i++){
        if(this->inMatrix[i][1] == prodNo ){
            sum += this->inMatrix[i][2];
        }
    }
    return sum;
}
float analyzer::getTotPersonProduct( float personNo, float prodNo ){
    float sum = 0;
    for ( int i = 0; i < this->inMatrix.size(); i++){
        if(this->inMatrix[i][0] == personNo && this->inMatrix[i][1] == prodNo ){
            sum += this->inMatrix[i][2];
        }
    }
    return sum;
}


void analyzer::printMatrix(){
    for ( int i = 0; i < this->inMatrix.size(); i++ ){
        for ( int j = 0; j < this->inMatrix[i].size(); j++){
            std::cout << this->inMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void analyzer::printTotPerson(float personNo, std::ofstream *stream){
    if ( stream->is_open() ){
        *stream << "Total sales by the person #" << personNo << " : " <<  this->getTotPerson(personNo) << std::endl;
    }
}

void analyzer::printTotPerson(float personNo){
        std::cout << "Total sales by the person #" << personNo << " : " <<  this->getTotPerson(personNo) << std::endl;
}

void analyzer::printTotProduct(float prodNo, std::ofstream *stream){
    if ( stream->is_open() ){
        *stream << "Total sales for the product #" << prodNo << " : " <<  this->getTotProduct(prodNo) << std::endl;
    }
}

void analyzer::printTotProduct(float prodNo){
    std::cout << "Total sales for the product #" << prodNo << " : " <<  this->getTotProduct(prodNo) << std::endl;
}

void analyzer::analyzeTotal(){
    int j;
    this->outMatrix.resize(5);
    for ( int i = 0; i < outMatrix.size(); i++ ){
        this->outMatrix[i].resize(4);
        for ( j = 0; j<this->outMatrix.size(); j++){
            this->outMatrix[i][j] = getTotPersonProduct((float) j, (float) i);
        }
    }
}

void analyzer::printTotal(){
    analyzeTotal();
    for ( int i = 0; i < this->outMatrix.size(); i++ ){
        for ( int j = 0; j < this->outMatrix[i].size(); j++){
            std::cout << this->outMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}








