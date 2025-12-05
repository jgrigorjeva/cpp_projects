#ifndef MUTANTSTACK
#define MUTANTSTACK

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    // define the iterator type
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator; // modern c++ contains also constant iterators that access the elements in a read-only manner

    // Access underlying container c
    // In dependent base classes, you must use "this->"
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }

    // not required by the subject
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end()   const { return this->c.end(); }

    const_iterator cbegin() const { return this->c.begin(); }
    const_iterator cend()   const { return this->c.end(); }
};

#endif
