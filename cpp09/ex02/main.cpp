#include <iostream>
#include <vector>

#include "inputValidation.hpp"

// If portable code should be produed, use _TCHAR instead of char for argv type
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "No argument given" << std::endl;
        return 1;
    }

    std::vector<int> sequence;
    for (int i = 1; i < argc; i++)
        if (!parseInput(argv[i], sequence))
            return 1;
    printInput(sequence);
    if (inputInvalid(sequence))
        return (1);

}
