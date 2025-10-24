#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    this->_brain = new Brain();
    this->_type = "Cat";
    std::cout << BG << "Default Cat constructor called\n" << RST;
}


Cat::Cat(std::string type)
{
    this->_brain = new Brain();
    this->_type = type;
    std::cout << BG<< "Parametrized Cat constructor called\n" << RST;
}
Cat::Cat(const Cat &other): Animal(other._type)
{
    this->_brain = new Brain();
    this->_type = other._type;
    std::cout << "Cat copy constructor called\n";
}
Cat &Cat::operator=(const Cat &other)
{
    
    std::cout << "Cat copy assignment constructor called\n";
    if (this != &other)
    {
        this->_brain = new Brain();
        this->_type = other._type;
    }
    return *this;
}
Cat::~Cat()
{
    delete _brain;
    std::cout << BR << "Cat destructor called\n" << RST;
}
void Cat::makeSound() const
{
    std::cout << BB <<"Meow\n" << RST;
}