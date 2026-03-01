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

    std::vector<int> sequenceVec;
    for (int i = 1; i < argc; i++)
        if (!parseInput(argv[i], sequenceVec))
            return 1;
    printContainerSingles(sequenceVec, "The original unsorted sequence: ");
    if (inputInvalid(sequenceVec))
        return (1);
    g_count = 0;
    std::vector<int> sortedVec = sortVector(sequenceVec);
    DEBUG_PRINT(std::cout << "Number of comparisons: " << g_count << std::endl);
    printContainerSingles(sortedVec, "Sorted vector:\n");
    g_count = 0;
    std::deque<int> sequenceDeq(sequenceVec.begin(), sequenceVec.end());
    std::deque<int> sortedDeq = sortDeque(sequenceDeq);
    DEBUG_PRINT(std::cout << "Number of comparisons: " << g_count << std::endl);
    printContainerSingles(sortedDeq, "Sorted deque:\n");
}
