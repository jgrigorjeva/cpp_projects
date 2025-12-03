#include "Span.hpp"

int main()
{
    Span span(10);
    span.addNumber(3);
    span.print();
    span.addNumbers(6, 42);
    span.print();
    span.addNumber(1);
    
    span.print();
    try
    {
        span.addNumbers(3, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}