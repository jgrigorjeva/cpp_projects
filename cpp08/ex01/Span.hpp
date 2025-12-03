#ifndef SPANHPP
#define SPANHPP

#include <exception>
#include <vector>

class Span
{
    private:
    unsigned int _maxN;
    unsigned int _storedN;
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
    void addNumberRange(int start, int end); // what exactly to do?

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

#endif