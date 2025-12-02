#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include "Colors.hpp"

template<typename Iter>
void print_range(Iter first, Iter last) {
    for (; first != last; ++first)
        std::cout << *first << " ";
}

int main()
{
    std::cout << BG "*** VECTORS ***\n" RST;

    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }
    print_range(vec.begin(), vec.end());
    std::cout << BR "\nneedle does not match vector elements: " RST;
    std::vector<int>::iterator iter = easyfind(vec, -100);
    std::cout<<"*iter: " << *iter << std::endl;
    std::cout << BB "needle does match vector elements: " RST;
    iter = easyfind(vec, 6);
    std::cout<<"*iter: " << *iter << std::endl;

    
    std::cout << BG "*** LISTS ***\n" RST;
    std::list<int> lst;
    for (int i = 0; i < 10; i++)
    {
        lst.push_back(i);
    }
    print_range(lst.begin(), lst.end());
    std::cout << BR "\nneedle does not match list elements: " RST;
    std::list<int>::iterator iterl = easyfind(lst, 200);
    std::cout<<"*iter: " << *iterl << std::endl;
    std::cout << BB "needle does match list elements: " RST;
    iterl = easyfind(lst, 6);
    std::cout<<"*iter: " << *iterl << std::endl;

     // forward list is from c++11
    // array is from c++11
    // inplace_vector is from c++26
    // hive is from c++26
    std::cout << BG "*** DEQUE ***\n";
    std::deque<int> deq;
    for (int i = 0; i < 10; i++)
    {
        deq.push_back(i);
    }
    std::deque<int>::iterator iterd;
    std::cout << BB "needle does not match deque elements: " RST;
    iterd = easyfind(deq, -100);
    std::cout<<"*iter: " << *iterd << std::endl;
    std::cout << BB "needle does match deque elements: " RST;
    // does exist
    iterd = easyfind(deq, 1);
    std::cout<<"*iter: " << *iterd << std::endl;

    
}

