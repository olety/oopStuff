//
//  analyzer.cpp
//  sales
//
//  Created by Oleksii Kyrylchuk on 10/19/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include "analyzer.hpp"



Analyzer::Analyzer(){
    int i=0,j;
    bool a = true;
    std::string line;
    while(a){
        this->inMatrix.resize(this->inMatrix.size()+1);
        this->inMatrix[i].resize(3);
        for ( j = 0; j < 3; j++){
            if ( !(std::cin >> this->inMatrix[i][j]) ){
                this->inMatrix.erase(this->inMatrix.begin()+i);
                a = false;
                break;
            }
            if ( this->inMatrix[i][j] < 0 || ((j==0)&&(this->inMatrix[i][j]>4)) || ((j==1)&&(this->inMatrix[i][j]>5))){
                this->inMatrix.erase(this->inMatrix.begin()+i);
                a = false;
                break;
            }
        }
        i++;
    }
}

Analyzer::Analyzer( std::ifstream *in ){
    int i=0,j;
    bool a = true;
    std::string line;
    while(a){
        this->inMatrix.resize(this->inMatrix.size()+1);
        this->inMatrix[i].resize(3);
        for ( j = 0; j < 3; j++){
            if ( !(*in >> this->inMatrix[i][j]) ){
                this->inMatrix.erase(this->inMatrix.begin()+i);
                a = false;
                break;
            }
            if ( this->inMatrix[i][j] < 0 || ((j==0)&&(this->inMatrix[i][j]>4)) || ((j==1)&&(this->inMatrix[i][j]>5))){
                this->inMatrix.erase(this->inMatrix.begin()+i);
                a = false;
                break;
            }
        }
        i++;
    }
}

Analyzer::~Analyzer(){
    for ( int i = 0; i < this->inMatrix.size(); i++ ){
        this->inMatrix[i].erase(this->inMatrix[i].begin(), this->inMatrix[i].end());
    }
    this->inMatrix.erase(this->inMatrix.begin(), this->inMatrix.end());
}


float Analyzer::getTotPerson(float personNo){
    float sum = 0;
    for ( int i = 0; i < this->inMatrix.size(); i++){
        if(this->inMatrix[i][0] == personNo ){
            sum += this->inMatrix[i][2];
        }
    }
    return sum;
}

float Analyzer::getTotProduct(float prodNo){
    float sum = 0;
    for ( int i = 0; i < this->inMatrix.size(); i++){
        if(this->inMatrix[i][1] == prodNo ){
            sum += this->inMatrix[i][2];
        }
    }
    return sum;
}
float Analyzer::getTotPersonProduct( float personNo, float prodNo ){
    float sum = 0;
    for ( int i = 0; i < this->inMatrix.size(); i++){
        if(this->inMatrix[i][0] == personNo && this->inMatrix[i][1] == prodNo ){
            sum += this->inMatrix[i][2];
        }
    }
    return sum;
}


void Analyzer::printMatrix(){
    for ( int i = 0; i < this->inMatrix.size(); i++ ){
        for ( int j = 0; j < this->inMatrix[i].size(); j++){
            std::cout << this->inMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Analyzer::printTotPerson(float personNo, std::ofstream *stream){
    if ( stream->is_open() ){
        *stream << "Total sales by the person #" << personNo << " : " <<  this->getTotPerson(personNo) << std::endl;
    }
}

void Analyzer::printTotPerson(float personNo){
        std::cout << "Total sales by the person #" << personNo << " : " <<  this->getTotPerson(personNo) << std::endl;
}

void Analyzer::printTotProduct(float prodNo, std::ofstream *stream){
    if ( stream->is_open() ){
        *stream << "Total sales for the product #" << prodNo << " : " <<  this->getTotProduct(prodNo) << std::endl;
    }
}

void Analyzer::printTotProduct(float prodNo){
    std::cout << "Total sales for the product #" << prodNo << " : " <<  this->getTotProduct(prodNo) << std::endl;
}

void Analyzer::analyzeTotal(){
    int j;
    this->outMatrix.resize(5);
    for ( int i = 0; i < outMatrix.size(); i++ ){
        this->outMatrix[i].resize(4);
        for ( j = 0; j<this->outMatrix.size(); j++){
            this->outMatrix[i][j] = getTotPersonProduct((float) j, (float) i);
        }
    }
}

void Analyzer::printTotal(){
    analyzeTotal();
    for ( int i = 0; i < this->outMatrix.size(); i++ ){
        for ( int j = 0; j < this->outMatrix[i].size(); j++){
            std::cout << this->outMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Analyzer::printTotal( std::ofstream *stream ){
    if ( stream->is_open() ){
        analyzeTotal();
        *stream << "-------ANALIZER MATRIX START---------" << std::endl;
        for ( int i = 0; i < this->outMatrix.size(); i++ ){
            for ( int j = 0; j < this->outMatrix[i].size(); j++){
                *stream << this->outMatrix[i][j] << " ";
            }
            *stream << std::endl;
        }
        *stream << "-------ANALIZER MATRIX END----------" << std::endl;
    }
}








