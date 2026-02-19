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
void printInput(std::vector<int> sequence);
bool inputInvalid(std::vector<int> sequence);
bool duplicatesFound(std::vector<int> sequence);

#endif