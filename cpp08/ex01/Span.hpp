#ifndef SPANHPP
#define SPANHPP

#include <exception>
#include <vector>
#include <iostream>

class Span
{
    private:
    unsigned int _maxN;
    // unsigned int _storedN;
    std::vector<int> _container;

    public:
    Span();
    Span(const unsigned int N);
    Span(const Span& other);
    ~Span();
    
    // operators
    Span& operator=(const Span& other);

    // members
    void addNumber(const int num);
    int shortestSpan() const;
    int longestSpan() const;
    void addNumbers(const std::size_t len, const int num); // appends number num len times
    unsigned int size() const;
    void print();

    // exceptions
    class SpanOverflowException : public std::exception{
        public:
        const char* what() const throw();
    };
    class SpanImpossibleException : public std::exception{
        public:
        const char* what() const throw();
    };
};

// std::ostream& operator<<(std::ostream& out, const Span& src)

#endif