#include "Array.hpp"
#include <iostream>
#include "Colors.hpp"

int main()
{
    std::cout << BOLD "Testing int arrays\n" RST;
    Array<int> emptyIntArr;
    Array<int> intArr(10);
    Array<int> copyIntArr(intArr);

    std::cout << "emptyIntArr size: " << emptyIntArr.size()<< std::endl;
    try
    {
        std::cout << "emptyIntArr element 0: " << emptyIntArr[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "intArr size: " << intArr.size()<< std::endl;
    std::cout << BG "Set element at index 5 to 5\n" RST;
    intArr.setElement(5, 5);
    std::cout << "intArr elements: ";
    for (unsigned int i = 0; i < intArr.size(); i++)
        std::cout << intArr[i] << ", ";
    std::cout << std::endl;
    try
    {
        std::cout << "intArr element 10: " << intArr[10] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << BOLD "\nTesting char arrays\n" RST;
    Array<char> emptyCharArr;
    Array<char> charArr(10);
    Array<char> copyCharArr(charArr);

    std::cout << "emptyCharArr size: " << emptyCharArr.size()<< std::endl;
    try
    {
        std::cout << "emptyCharArr element 0: " << emptyCharArr[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "charArr size: " << charArr.size()<< std::endl;
    std::cout << "charArr elements: ";
    for (unsigned int i = 0; i < charArr.size(); i++)
        std::cout << charArr[i] << ", ";
    std::cout << std::endl;
    try
    {
        std::cout << "charArr element 10: " << charArr[10] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


}