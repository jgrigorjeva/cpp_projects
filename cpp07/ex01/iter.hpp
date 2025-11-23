#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// for mutable arrays
template <typename T, typename Func>
void iter(T* array, const int len, Func f)
{
    for (int i = 0; i<len; i++)
    {
        f(array[i]);
    }
}

// for const arrays
template <typename T, typename Func>
void iter(const T* array, const int len, Func f)
{
    for (int i = 0; i<len; i++)
    {
        f(array[i]);
    }
}
// for mutable elements
template <typename T>
void changePrintElement(T& element)
{
    element += 1;
    std::cout << element << std::endl;
}

// for const elements
template <typename T>
void printElement(const T& element)
{
    std::cout << element << std::endl;
}
#endif