#include "Span.hpp"
#include "Colors.hpp"

Span::Span(): _maxN(0)
{
}

Span::Span(const unsigned int N): _maxN(N)
{

}
Span::Span(const Span& other): _maxN(other._maxN), _container(other._container)
{

}
Span::~Span(){}

// operators
Span& Span::operator=(const Span& other)
{
    if (this == &other)
        return *this;
    _maxN = other._maxN;
    _container = other._container;
    return *this;
}

// members
void Span::addNumber(const int num)
{
    if (_container.size() == _maxN)
        throw SpanOverflowException();
    _container.push_back(num);
}

void Span::addNumbers(const std::size_t len, const int num)
{
    if (_container.size() + len <= _maxN)
        _container.insert(_container.end(), len, num);
    else
        throw SpanOverflowException();
}
int Span::shortestSpan() const
{
    if (_container.size() < 2)
        throw SpanImpossibleException();
    return 0;
}

int Span::longestSpan() const
{
    if (_container.size() < 2)
        throw SpanImpossibleException();
    return 0;
}

unsigned int Span::size() const
{
    return _container.size();
}

void Span::print()
{
    for (unsigned int i = 0; i < _container.size(); i++)
    {
        std::cout << _container[i];
        if (i < _container.size() - 1)
            std::cout << ", ";
        else
            std::cout << std::endl;
    }

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

// // ostream
// std::ostream& operator<<(std::ostream& out, const Span& src)
// {
//     for (unsigned int i = 0; i < src.size(); i++)
//     {
//         out << _container.begin()
//     }
// }
