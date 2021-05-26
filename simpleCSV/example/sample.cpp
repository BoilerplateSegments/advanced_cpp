#include "csv.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

template<typename T>
void print(std::vector<std::vector<T>> &v){
    for(std::vector<T> row:v){
        for(T col:row){
            std::cout<<col<< " ";
        }
        std::cout<<std::endl;
    }
}

int main(){

    std::ifstream file("nice.csv");

    using c2d = std::vector<std::vector<std::string>>;
    c2d nice;

    while (!file.eof()){
        nice.emplace_back(lineTokenizer1(file));
    }

    print(nice);

    return 0;
}