#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
// #include <tgmath.h> 
// #include <cmath> 
// #include <ctgmath>
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
    if (type == "char")
    {
        fromChar(literal);
        return;
    }
    if (type == "int")
    {
        fromInt(literal);
        return;
    }
    if (type == "double" || type == "float")
        fromDouble(literal);
    
        
}

std::string ScalarConverter::getType(std::string literal)
{
    int dot = 0;
    if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])) )
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
// maybe hadle unsigned inf and inff as well?
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
    printResultFromString(charStr, charStr, floatStr, doubleStr);

}

void ScalarConverter::printResultFromString(std::string charStr, std::string intStr, std::string floatStr, std::string doubleStr)
{
    std::cout << "char: " << charStr << std::endl;
    std::cout << "int: " << intStr << std::endl;
    std::cout << "float: " << floatStr << std::endl;
    std::cout << "double: " << doubleStr << std::endl;
}

int ScalarConverter::charToInt(char ch)
{
    return (static_cast<unsigned char>(ch));
}

void ScalarConverter::printResultFromNum(std::string charStr, int i, float f, double d)
{

    std::cout << "char: " << charStr << std::endl;
    if (i-f >=1 || i-f <= -1)
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if (f/(float)i == 1)
    {
        std::cout << "float: " << f << ".0" << std::endl;
        std::cout << "double: " << d << ".0f" << std::endl;
    }
    else
    {
        std::cout << "float: " << f << std::endl;
        std::cout << "double: " << d << "f"<< std::endl;
    }
     
    
}

void ScalarConverter::fromChar(std::string literal)
{

    std::string num = "impossible";
    if (!std::isprint(static_cast<unsigned char>(literal[0])))
    {
        printResultFromString("Non displayable", num, num, num);
        return ;
    }
    int i = charToInt(literal[0]);
    float f = (float)i;
    double d = (double)i;
    printResultFromNum(literal, i, f, d);
}

void ScalarConverter::fromInt(std::string literal)
{
    std::string ch;
    int i = atoi(literal.c_str());
    ch = getCharFromInt(i);
    double d = (double)i;
    float f = (float)i;
    printResultFromNum(ch, i, f, d);
}

void ScalarConverter::fromDouble(std::string literal)
{
    int i = atoi(literal.c_str());
    double d = atof(literal.c_str());
    float f = (float)d;
    std::string ch;
    if ((double)i / d == 1)
        ch = getCharFromInt(i);
    else
        ch = "impossible";
    printResultFromNum(ch, i, f, d);

}

std::string ScalarConverter::getCharFromInt(int i)
{
    std::string ch;
    if (i >= 0 && i <= 127 && std::isprint(static_cast<unsigned char>(i)))
        ch = i;
    else if (i >= 0 && i <= 127)
        ch = "Non displayable";
    else
        ch = "impossible";
    return ch;
}