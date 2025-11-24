#include "Array.hpp"
#include <iostream>
#include "Colors.hpp"

int main()
{
    std::cout << BOLD "Testing int arrays\n" RST;
    Array<int> emptyIntArr;
    Array<int> intArr(10);

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
    std::cout << BG "Set element at index 5 to = 5\n" RST;
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

    // copy array
    Array<int> copyIntArr(intArr);
    std::cout << "copyIntArr size: " << copyIntArr.size()<< std::endl;
    std::cout << "copyIntArr elements: ";
    for (unsigned int i = 0; i < copyIntArr.size(); i++)
        std::cout << copyIntArr[i] << ", ";
    std::cout << std::endl;

    // = operator overload test
    Array<int> equalIntArr;
    equalIntArr = intArr;
    std::cout << "equalIntArr size: " << equalIntArr.size()<< std::endl;
    std::cout << "equalIntArr elements: ";
    for (unsigned int i = 0; i < equalIntArr.size(); i++)
        std::cout << copyIntArr[i] << ", ";
    std::cout << std::endl;

    // change intArr
    std::cout << BG "Set element in the intArr at index 0 to = 3\n" RST;
    intArr.setElement(0, 3);
    std::cout << "intArr elements: ";
    for (unsigned int i = 0; i < intArr.size(); i++)
        std::cout << intArr[i] << ", ";
    std::cout << std::endl;
    std::cout << "copyIntArr elements: ";
    for (unsigned int i = 0; i < copyIntArr.size(); i++)
        std::cout << copyIntArr[i] << ", ";
    std::cout << std::endl;
    std::cout << "equalIntArr elements: ";
    for (unsigned int i = 0; i < equalIntArr.size(); i++)
        std::cout << copyIntArr[i] << ", ";
    std::cout << std::endl;

    
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
    std::cout << BG "Set element at index 2 to 'e'\n" RST;
    charArr.setElement(2, 'e');
    for (unsigned int i = 0; i < charArr.size(); i++)
        std::cout << charArr[i] << ", ";
    std::cout << std::endl;


}