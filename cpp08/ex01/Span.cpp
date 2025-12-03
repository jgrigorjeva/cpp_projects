#include "Span.hpp"
#include "Colors.hpp"

Span::Span(): _maxN(0), _storedN(0)
{
}

Span::Span(const unsigned int N): _maxN(N), _storedN(0)
{

}
Span::Span(const Span& other): _maxN(other._maxN), _storedN(other._storedN), _container(other._container)
{

}
Span::~Span(){}

// operators
Span& Span::operator=(const Span& other)
{
    if (this == &other)
        return *this;
    _maxN = other._maxN;
    _storedN = other._storedN;
    _container = other._container;
}

// members
void Span::addNumber(const int num)
{
    if (_storedN == _maxN)
        throw SpanOverflowException();
    _container.push_back(num);
    _storedN++;
}
int Span::shortestSpan() const
{
    if (_storedN < 2)
        throw SpanImpossibleException();
}

int Span::longestSpan() const
{
    if (_storedN < 2)
        throw SpanImpossibleException();
}

// exceptions
const char* Span::SpanOverflowException::what() const throw()
{
    return (BR "Impossible to add an element, the container is full!" RST);
}

const char* Span::SpanImpossibleException::what() const throw()
{
    return (BR "Span does not exist!" RST);
}