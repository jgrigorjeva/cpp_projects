#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    this->_type = "Cat";
    std::cout << "Default Cat constructor called\n";
}


Cat::Cat(std::string type)
{
    this->_type = type;
    std::cout << "Parametrized Cat constructor called\n";
}
Cat::Cat(const Cat &other): Animal(other._type)
{
    this->_type = other._type;
    std::cout << "Cat copy constructor called\n";
}
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment constructor called\n";
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}
Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}
void Cat::makeSound()
{
    std::cout << "Meow\n";
}