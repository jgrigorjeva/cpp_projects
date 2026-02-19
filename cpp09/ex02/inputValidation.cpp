#include "inputValidation.hpp"

bool inputInvalid(std::vector<int> sequence)
{
    if (sequence.size() < 1)
    {
        std::cerr << "Error: no valid number to sort" << std::endl;
        return true;
    }
    
    if (duplicatesFound(sequence))
    {
        std::cerr << "Error: duplicates found" << std::endl;
        return true;
    }
    return false;

}

bool parseInput(char *arg, std::vector<int> &sequence)
{
    for (;;)
    {
        // errno can be set to any non-zero value by a library function call
        // regardless of whether there was an error, so it needs to be cleared
        // in order to check the error set by strtol
        errno = 0;
        char* arg_end;
        const long i = std::strtol(arg, &arg_end, 10);
        if (i < 0)
        {
            std::cerr << "error: negative number encountered" << std::endl;
            return false;
        }
        if (arg == arg_end)
            break;
 
        const bool range_error = errno == ERANGE;
        const std::string extracted(arg, arg_end - arg);
        arg = arg_end;
        if (range_error)
        {
            std::cerr << "Range error occurred." << std::endl;
            return false;
        }
        sequence.push_back(i);
     }
    return true;
}

void printInput(std::vector<int> sequence)
{
    for (std::vector<int>::iterator it = sequence.begin(); it != sequence.end(); ++it)
        std::cout << *it << ", ";
    std::cout << std::endl;
}

bool duplicatesFound(std::vector<int> sequence)
{
    std::set<int> s(sequence.begin(), sequence.end());

    if (sequence.size() != s.size())
        return true;

    return false;
}