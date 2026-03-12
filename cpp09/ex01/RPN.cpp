#include "RPN.hpp"

float getResult(std::string expr)
{
    
}

// exceptions
const char* InvalidExpressionException::what() const throw()
{
    return ("The expression is invalid");
}