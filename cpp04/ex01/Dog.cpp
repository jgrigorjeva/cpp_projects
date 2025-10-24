#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    this->_type = "Dog";
    std::cout << BG << "Default Dog constructor called\n" << RST;
}


Dog::Dog(std::string type)
{
    this->_type = type;
    std::cout << BG << "Parametrized Dog constructor called\n" << RST;
}
Dog::Dog(const Dog &other): Animal(other._type)
{
    this->_type = other._type;
    std::cout << BG << "Dog copy constructor called\n" << RST;
}
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment constructor called\n";
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}
Dog::~Dog()
{
    std::cout << BR << "Dog destructor called\n" << RST;
}
void Dog::makeSound() const
{
    std::cout << BB << "Woof\n" << RST;
}