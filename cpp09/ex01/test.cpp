#include <string>
#include <iostream>
#include <stack>
#include "algorithm"
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <cctype>
#include <limits>
#include <sstream>

int main()
{
    std::string word = "3 4 2";
    std::string word1 = word.substr(0, 1);
    std::string word2 = word.substr(2, 3);
    std::string word3 = word.substr(4, 5);
    std::cout   << word1 
                << "\n"
                << word2
                << "\n"
                << word3
                << std::endl;
}