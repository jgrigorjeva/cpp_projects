#include <deque>
#include "easyfind.hpp"

int main()
{
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
    // does not exist
    iterd = easyfind(deq, -100);
    // does exist
    iterd = easyfind(deq, 1);
    
}