#include <iostream>

void printError();


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printError();
        return 1;
    }
    
}

void printError()
{
    std::cerr << "Error\n";
}