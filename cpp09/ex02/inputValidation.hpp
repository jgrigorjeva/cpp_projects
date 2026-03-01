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
    for (typename T::iterator it = sequence.begin(); it != sequence.end(); ++it)
        std::cout << *it << ", ";
    std::cout << std::endl;
}

#endif