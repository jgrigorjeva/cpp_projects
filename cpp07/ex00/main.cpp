#include "whatever.hpp"
#include <iostream>
#include "Colors.hpp"

int main()
{
    std::cout << BG "Testing the swap template\n" RST;
    std::cout << BOLD "Swap int values\n" RST;
    int i = 1;
    int j = 2;

    std::cout << i << ", " << j << std::endl;
    // Whatever::swap(i, j);
    ::swap(i, j);
    std::cout << i << ", " << j << std::endl;

    std::cout << BOLD "Swap char values\n" RST;
    char ch1 = 'k';
    char ch2 = 'l';
    std::cout << ch1 << ", " << ch2 << std::endl;
    // Whatever::swap(ch1, ch2);
    ::swap(ch1, ch2);
    std::cout << ch1 << ", " << ch2 << std::endl;

    std::cout << BOLD "Swap std::string values\n" RST;
    std::string s1 = "Hello";
    std::string s2 = "World";
    std::cout << s1 << ", " << s2 << std::endl;
    // Whatever::swap(s1, s2);
    ::swap(s1, s2);
    std::cout << s1 << ", " << s2 << std::endl;

    std::cout << BG "\nTesting the min template\n" RST;
    std::cout << BOLD "int values\n" RST;
    std::cout << "arg1: " << i << ", arg2: " << j << ", min: " << ::min(i, j) << std::endl;
    std::cout << BOLD "char values\n" RST;
    std::cout << "arg1: " << ch1 << ", arg2: " << ch2 << ", min: " << ::min(ch1, ch2) << std::endl;
    std::cout << BOLD "str values\n" RST;
    std::cout << "arg1: " << s1 << ", arg2: " << s2 << ", min: " << ::min(s1, s2) << std::endl;

    std::cout << BG "\nTesting the max template\n" RST;
    std::cout << BOLD "int values\n" RST;
    std::cout << "arg1: " << i << ", arg2: " << j << ", min: " << ::max(i, j) << std::endl;
    std::cout << BOLD "char values\n" RST;
    std::cout << "arg1: " << ch1 << ", arg2: " << ch2 << ", min: " << ::max(ch1, ch2) << std::endl;
    std::cout << BOLD "str values\n" RST;
    std::cout << "arg1: " << s1 << ", arg2: " << s2 << ", min: " << ::max(s1, s2) << std::endl;
}
