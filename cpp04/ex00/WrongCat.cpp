#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
    std::cout << "Default WrongCat constructor called\n";
}


WrongCat::WrongCat(std::string type)
{
    this->_type = type;
    std::cout << "Parametrized WrongCat constructor called\n";
}
WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other._type)
{
    this->_type = other._type;
    std::cout << "WrongCat copy constructor called\n";
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat copy assignment constructor called\n";
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}
void WrongCat::makeSound() const
{
    std::cout << "Meow\n";
}