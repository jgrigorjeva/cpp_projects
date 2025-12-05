#include "Span.hpp"
#include "Colors.hpp"
#include <algorithm>

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
    // make a temporary sorted vector
    std::vector<int> temp = _container;
    std::sort(temp.begin(), temp.end());
    int sSpan = temp[temp.size() - 1] - temp[0];

    for (long unsigned int i = 1; i < temp.size(); i++)
    {
        if (temp[i] - temp[i-1] < sSpan)
            sSpan = temp[i] - temp[i-1];
    }
    return sSpan;
}

int Span::longestSpan() const
{
    if (_container.size() < 2)
        throw SpanImpossibleException();
    // make a temporary sorted vector
    std::vector<int> temp = _container;
    std::sort(temp.begin(), temp.end());
    return temp[temp.size() - 1] - temp[0];
}

unsigned int Span::size() const
{
    return _container.size();
}

void Span::print()
{
    std::cout << BOLD "Container elements: " RST;
    if (_container.size() == 0)
        std::cout << "Container is empty\n";
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
