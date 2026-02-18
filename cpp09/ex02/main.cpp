#include <iostream>
#include <vector>
#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <string>

// bool inputInvalid(int argc, char **argv);
bool parseInput(char *arg, std::vector<int> &sequence);

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
    // if (inputInvalid(argc, argv))
    //     return (1);

}

// bool inputInvalid(int argc, char **argv)
// {
    
    

//     // if (cuplicatesFound(argv))

// }

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
        sequence.push_back(i);
        if (arg == arg_end)
            break;
 
        const bool range_error = errno == ERANGE;
        const std::string extracted(arg, arg_end - arg);
        arg = arg_end;
 
        std::cout << "Extracted " << extracted
                  << ", strtol returned " << i << '.';
        if (range_error)
        {
            std::cout << "\n  Range error occurred.";
            return false;
        }
            
 
        std::cout << '\n';
    }
    return true;
}