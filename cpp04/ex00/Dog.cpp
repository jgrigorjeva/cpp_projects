#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    this->_type = "Dog";
    std::cout << "Default Dog constructor called\n";
}


Dog::Dog(std::string type)
{
    this->_type = type;
    std::cout << "Parametrized Dog constructor called\n";
}
Dog::Dog(const Dog &other): Animal(other._type)
{
    this->_type = other._type;
    std::cout << "Dog copy constructor called\n";
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
    std::cout << "Dog destructor called\n";
}
void Dog::makeSound() const
{
    std::cout << "Woof\n";
}