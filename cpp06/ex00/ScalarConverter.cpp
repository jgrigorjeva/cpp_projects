#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
// #include <cctype>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}
ScalarConverter::~ScalarConverter(){}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

// convert

void ScalarConverter::convert(std::string literal)
{
    if (literal.length() == 0)
        return;
    if (isFun(literal))
    {
        handleFun(literal);
        return ;
    }
    
    std::string type = getType(literal);
    std::cout << type << std::endl;
}

std::string ScalarConverter::getType(std::string literal)
{
    int dot = 0;
    if (literal.length() == 1 && std::isprint(static_cast<unsigned char>(literal[0])) && !std::isdigit(static_cast<unsigned char>(literal[0])) )
        return "char";
    int i = 0;    
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    while (literal[i] && std::isdigit(static_cast<unsigned char>(literal[i])))
        i++;
    if (literal[i] && literal[i] == '.')
        dot = i++;
    while (literal[i] && std::isdigit(static_cast<unsigned char>(literal[i])))
        i++;
    if (literal[i] && literal[i] == 'f')
    {
        if (dot && dot + 1 < i && !literal[i+1])  
            return "float";
        else
            return "invalid";
    }
    if (dot && dot + 1 < i && !literal[i])
        return ("double");
    if (dot == 0 && !literal[i])
        return "int";
    return "invalid";
    
}

bool ScalarConverter::isFun(std::string literal)
{
    return (literal == "-inff" || literal == "+inff" || literal == "nanf"
    || literal == "-inf" || literal == "+inf" || literal == "nan");
}

void ScalarConverter::handleFun(std::string literal)
{
    std::string charStr = "impossible";
    std::string floatStr;
    std::string doubleStr;
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        doubleStr = literal;
        floatStr = literal + "f";
    }
    else
    {
        floatStr = literal;
        doubleStr = literal;
        doubleStr.erase(literal.length() - 1);
    }
    printResult(charStr, charStr, floatStr, doubleStr);
}

void ScalarConverter::printResult(std::string charStr, std::string intStr, std::string floatStr, std::string doubleStr)
{
    std::cout << "char: " << charStr << std::endl;
    std::cout << "int: " << intStr << std::endl;
    std::cout << "float: " << floatStr << std::endl;
    std::cout << "double: " << doubleStr << std::endl;
}