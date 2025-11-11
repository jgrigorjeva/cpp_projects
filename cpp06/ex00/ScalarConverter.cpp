#include "ScalarConverter.hpp"
#include <string>
#include <cctype>

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
        
    getType(literal);
}

std::string ScalarConverter::getType(std::string literal)
{
    if (literal.length() == 1 && std::isalpha(static_cast<unsigned char>(literal[0])) )
        return "char";
    else if
}

bool ScalarConverter::isFun(std::string literal)
{
    return (literal == "-inff" || literal == "+inff" || literal == "nanf"
    || literal == "-inf" || literal == "+inf" || literal == "nan");
}

void ScalarConverter::handleFun(std::string literal)
{
    std::string charStr = "impossible";
    std::string intStr = charStr;
    std::string floatStr;
    std::string doubleStr;
    
}