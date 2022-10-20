#include <iostream>
#include "funcs.h"

int main(){
    std::cout << removeLeadingSpaces("       int x = 1;  ") << std::endl;
    std::cout << countChar("    xjkxkjlxxx  \n", 'x') << std::endl;
    formatFile("brokenFile.txt", "fixedFile.txt");
    return 0;
}