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
    static void printResultFromString(std::string charStr, std::string intStr, std::string floatStr, std::string doubleStr);
    static void printResultFromNum(std::string charStr, int i, float f, double d);

    static void fromChar(std::string literal);
    static void fromInt(std::string literal);
    static void fromDouble(std::string literal);


    static int charToInt(char ch);
    static std::string getCharFromInt(int i);
    public:
    static void convert(std::string literal);
};

#endif