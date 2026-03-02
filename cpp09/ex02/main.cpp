#include <iostream>
#include <vector>
#include <ctime>

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
    printContainerSingles(sequenceVec, "Before: ");
    if (inputInvalid(sequenceVec))
        return (1);
    g_count = 0;

    // time measurement
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    // sorting
    std::vector<int> sortedVec = sortVector(sequenceVec);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    long vecSeconds = end.tv_sec - start.tv_sec;
    long vecNanoseconds = end.tv_nsec - start.tv_nsec;
    double vecElapsed = vecSeconds + vecNanoseconds * 1e-9;
    

    DEBUG_PRINT(std::cout << "Number of comparisons: " << g_count << std::endl);
    // DEBUG_PRINT(printContainerSingles(sortedVec, "Sorted vector:\n"));

    g_count = 0;
    std::deque<int> sequenceDeq(sequenceVec.begin(), sequenceVec.end());
    clock_gettime(CLOCK_MONOTONIC, &start);
    std::deque<int> sortedDeq = sortDeque(sequenceDeq);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    long deqSeconds = end.tv_sec - start.tv_sec;
    long deqNanoseconds = end.tv_nsec - start.tv_nsec;
    double deqElapsed = deqSeconds + deqNanoseconds * 1e-9;

    // the output
    printContainerSingles(sortedVec, "After: ");

    std::cout << "Time to process " << sequenceVec.size() << " elements with std::vector : " << vecElapsed << " us" << std::endl;
    std::cout << "Time to process " << sequenceDeq.size() << " elements with std::deque  : " << deqElapsed << " us" << std::endl;
}
