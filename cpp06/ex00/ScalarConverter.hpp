#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>

class ScalarConverter
{
    private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter();
    ScalarConverter & operator=(const ScalarConverter& other);
    static std::string getType(std::string literal);
    static bool isFun(std::string literal);
    static void handleFun(std::string literal);
    public:
    static void convert(std::string literal);
};

#endif