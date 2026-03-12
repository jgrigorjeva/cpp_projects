#ifndef RPNHPP
#define RPNHPP

#include <stack>
#include <iostream>

float getResult(std::string expr);

// exceptions
class InvalidExpressionException : public std::exception 
{
    public:
    const char*		what() const throw();
};

#endif