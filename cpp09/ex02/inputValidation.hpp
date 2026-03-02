#ifndef INPUTVALIDATION
#define INPUTVALIDATION

#include <iostream>
#include <vector>
#include <set>
#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <iterator>
#include <algorithm>

bool parseInput(char *arg, std::vector<int> &sequence);
// void printContainerSingles(std::vector<int> sequence);
bool inputInvalid(std::vector<int> sequence);
bool duplicatesFound(std::vector<int> sequence);

template <typename T>
void printContainerSingles(T sequence, std::string msg="")
{
    std::cout << msg;
    int i = 1;
    bool shorten = false;
    if (sequence.size() > 5)
        shorten = true;
    #ifdef DEBUG
    for (typename T::iterator it = sequence.begin(); it != sequence.end(); ++it)
    {
        std::cout << *it << " ";
    }
    (void)i;
    #else
    for (typename T::iterator it = sequence.begin(); it != sequence.end(); ++it)
    {
        if (shorten && i > 4)
        {
            std::cout << "[...]";
            break;
        }
        std::cout << *it << " ";
        i++;
    }
    #endif
    std::cout << std::endl;
}

#endif