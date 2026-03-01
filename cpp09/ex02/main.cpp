#include <iostream>
#include <vector>

#include "inputValidation.hpp"
#include "PmergeMe.hpp"

volatile int g_count;

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
    printContainerSingles(sequence, "The original unsorted sequence: ");
    if (inputInvalid(sequence))
        return (1);
    g_count = 0;
    std::vector<int> sorted = sortVector(sequence);
    DEBUG_PRINT(std::cout << "Number of comparisons: " << g_count << std::endl);
    printContainerSingles(sorted);


}
