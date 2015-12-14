//
//  main.cpp
//  caesar
//
//  Created by Oleksii Kyrylchuk on 7/16/15.
//  Copyright (c) 2015 olety. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>

int main(void) {
    std::fstream alpha, out;
    alpha.open("alpha.txt");
    out.open("out.txt",std::fstream::out);
    std::vector <std::string> strings;
    int stringsIt = -1;
    char alphabet[26];
    int i = 0,offset = 0;
    
    std::string line;
    for ( i = 0; i < 26; i++ ){
        alpha.get(alphabet[i]);
    }
    std::cout << "input your offset (-1 for trying all)" << std::endl;
    std::cin >> offset;
    std::cout << "input your data, then write HALT to stop. data will be saved in out.txt" << std::endl;
    
    std::getline(std::cin, line);
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    
    while ( line.compare("halt") != 0 ){
        strings.resize(strings.size()+1);
        stringsIt++;
        strings[stringsIt] = line;
        std::getline(std::cin, line);
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    }
    
    if ( offset == -1 ){
        for ( int off = 0; off < 27; off ++ ){
            out << std::endl << "OFFSET = " << off << std::endl;
            for ( int k = 1; k <= stringsIt; k++){
                for ( int j = 0; j < strings[k].length(); j++ ){
                    out << alphabet[(strings[k].c_str()[j]-97+off)%26];
                }
                out << std::endl;
            }
        }
    } else {
        for ( int k = 1; k <= stringsIt; k++){
            for ( int j = 0; j < strings[k].length(); j++ ){
                if ( strings[k].c_str()[j] == ' '){
                    out << " ";
                    continue;
                } else {
                    out << alphabet[(strings[k].c_str()[j]-97+offset)%26];
                }
            }
            out << std::endl;
        }
    }
    return 0;
}
