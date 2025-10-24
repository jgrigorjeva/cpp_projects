#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    this->_type = "Dog";
    this->_brain = new Brain();

    std::cout << BG << "Default Dog constructor called\n" << RST;
}


Dog::Dog(std::string type)
{
    this->_type = type;
    this->_brain = new Brain();
    std::cout << BG << "Parametrized Dog constructor called\n" << RST;
}
Dog::Dog(const Dog &other): Animal(other._type)
{
    this->_type = other._type;
    this->_brain = new Brain();
    for (int i=0; i < 100; i++)
    {
        this->set_idea(i, other.get_idea(i));
    }
    std::cout << BG << "Dog copy constructor called\n" << RST;
}
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment constructor called\n";
    if (this != &other)
    {
        if (_brain)
            delete _brain;
        this->_brain = new Brain();
        for (int i=0; i < 100; i++)
        {
            this->set_idea(i, other.get_idea(i));
        }
        this->_type = other._type;
    }
    return *this;
}
Dog::~Dog()
{
    delete _brain;
    std::cout << BR << "Dog destructor called\n" << RST;
}
void Dog::makeSound() const
{
    std::cout << BB << "Woof\n" << RST;
}

void Dog::set_idea(int index, std::string idea)
{
    _brain->set_idea(index, idea);
}

std::string Dog::get_idea(int index) const
{
    return (_brain->get_idea(index));
}