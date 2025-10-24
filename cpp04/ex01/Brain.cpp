#include "Brain.hpp"

Brain::Brain(){ std::cout << BG << "Brain default constructor called\n" << RST; }

Brain::Brain(std::string ideas[100])
{
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = ideas[i];
    }
    std::cout << BG << "Brain parametrized constructor called\n" << RST;
}
Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = other._ideas[i];
    }
    std::cout << BG << "Brain copy constructor called\n" << RST;
}
Brain::~Brain(){ std::cout << BR << "Brain default destructor called\n" << RST; }

void Brain::set_idea(int index, std::string idea)
{
    if (index < 0 || index >= 100) 
        return ;
    _ideas[index] = idea;
}
