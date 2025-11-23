#include "iter.hpp"
#include <iostream>
#include "Colors.hpp"

int main()
{
    std::cout << BG "First try mutable arrays\n" RST;
    int intArray[] = {1,2,3,4,5,6};
    int *p = intArray;
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::string strArray[] = {"str1", "str2", "str3", "str4"};

    std::cout << BOLD "print intArray\n" RST;
    iter(p, 6, changePrintElement<int>);

    std::cout << BOLD "\nprint charArray\n" RST;
    iter(charArray, 5, changePrintElement<char>);

    std::cout << BOLD "\nprint strArray\n" RST;
    iter(strArray, 4, changePrintElement<std::string>);

    std::cout << BG "\nNow try const arrays\n" RST;
    const int intArrayC[] = {1,2,3,4,5,6};
    const char charArrayC[] = {'a', 'b', 'c', 'd', 'e'};
    const std::string strArrayC[] = {"str1", "str2", "str3", "str4"};

    std::cout << BOLD "print intArrayC\n" RST;
    iter(intArrayC, 6, printElement<int>);

    std::cout << BOLD "\nprint charArrayC\n" RST;
    iter(charArrayC, 5, printElement<char>);

    std::cout << BOLD "\nprint strArrayC\n" RST;
    iter(strArrayC, 4, printElement<std::string>);


    return 0;
}