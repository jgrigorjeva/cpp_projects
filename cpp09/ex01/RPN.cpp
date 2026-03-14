#include "RPN.hpp"
#include <cstring>

double calculateRPN(std::string expr)
{
    std::stack<double> nstack;
    for (unsigned int i = 0; i < expr.size(); i++)
    {
        if (expr[i] == ' ')
        {}
        else if (isdigit(expr[i]))
            nstack.push(expr[i] - '0');
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            if (nstack.size() < 2)
                throw InvalidExpressionException();
            double b = nstack.top();
            nstack.pop();
            double a = nstack.top();
            nstack.pop();
            double result;
            switch (expr[i])
            {
            case '+':
                result = a+b;
                break;
            case '-':
                result = a-b;
                break;
            case '*':
                result = a*b;
                break;
            case '/':
                result = a/b;
                break;
            default:
                result = 0;
                break;
            }          
            nstack.push(result);
        }
        else
        {
            throw InvalidExpressionException();
        }
    }
    
    if (nstack.size() != 1)
        throw InvalidExpressionException();
    return (nstack.top());
    
}

// exceptions
const char* InvalidExpressionException::what() const throw()
{
    return ("Error");
}