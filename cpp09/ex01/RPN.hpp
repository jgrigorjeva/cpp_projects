#ifndef RPNHPP
#define RPNHPP

#include <stack>
#include <iostream>
#include <string>

double calculateRPN(std::string expr);

// exceptions
class InvalidExpressionException : public std::exception 
{
    public:
    const char*		what() const throw();
};

#endif