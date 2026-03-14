#include <iostream>
#include "RPN.hpp"

void printError();


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printError();
        return 1;
    }
    try
    {
        double result = calculateRPN(argv[1]);
        std::cout << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }  
    return 0;    
    
}

void printError()
{
    std::cerr << "Error\n";
}