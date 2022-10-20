#include <iostream>
#include <fstream>
#include "funcs.h"

std::string removeLeadingSpaces(std::string line){
    int i = 0;
    while(isspace(line[i])){
        i++;
    }
    return line.substr(i);
}

int countChar(std::string line, char c){
    int i;
    int count = 0;
    for(i = 0; i < line.length(); i++){
        if (line[i] == c){
            count++;
        }
    }
    return count;
}

void formatFile(std::string inputFile, std::string outputFile){
    std::ifstream rf(inputFile);
    std::ofstream wf(outputFile);
    std::string l;
    int indents = 0;
    int j;
    while(std::getline(rf, l)){
        l = removeLeadingSpaces(l);
        if (l[0] == '}'){
            indents--;
        }
        for(j = 0; j < indents; j++){
            wf << "\t";
        }
        wf << l << std::endl;;
        indents += countChar(l, '{');
        indents -= countChar(l, '}');
    }
}