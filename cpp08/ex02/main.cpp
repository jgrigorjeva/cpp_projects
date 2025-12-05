#include "MutantStack.hpp"
#include <iostream>
#include "Colors.hpp"

template<typename Iter>
void print_range(Iter first, Iter last) {
    for (; first != last; ++first)
        std::cout << *first << " ";
}

int main()
{
    std::cout << BOLD "Create and print a mutant stack\n" RST;
    MutantStack<int> mstack;
    for (int i = 0; i < 10; i++)
    {
        mstack.push(i);
    }
    print_range(mstack.begin(), mstack.end());

    std::cout << BOLD "\npop last element\n" RST;
    mstack.pop();
    print_range(mstack.begin(), mstack.end());

    std::cout << BOLD "\nget size\n" RST;
    std::cout << mstack.size() << std::endl;

    std::cout << BOLD "Use iterator\n" RST;
    std::cout << "first element: " << *mstack.begin() <<", last element: " << *(mstack.end()-1) << std::endl;

    // The swap member function is since c++11 :/
    // std::cout << BOLD "\nswap elements\n" RST;
    // MutantStack<int> to_swap;
    // for (int i = 0; i < 10; i++)
    // {
    //     to_swap.push(10-i);
    // } 
    // std::cout << "stack to swap: ";
    // print_range(to_swap.begin(), to_swap.end());
    // mstack.swap(to_swap);
    // std::cout << "Swapped stack mstack: ";
    // print_range(mstack.begin(), mstack.end());

}