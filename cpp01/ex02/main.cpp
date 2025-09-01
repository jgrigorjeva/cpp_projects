#include <iostream>

int main()
{
    std::string string_var = "HI THIS IS BRAIN";
    std::string &stringREF = string_var;
    std::string* stringPTR = &string_var;

    std::cout << "The memory address of the string variable: " << &string_var << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR<< std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF<< std::endl;
    std::cout << "The value of the string variable: " << string_var << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR<< std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF<< std::endl;
    return (0);
}