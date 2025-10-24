#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
    std::cout << BG << "Default WrongCat constructor called\n" << RST;
}


WrongCat::WrongCat(std::string type)
{
    this->_type = type;
    std::cout << BG << "Parametrized WrongCat constructor called\n"<< RST;
}
WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other._type)
{
    this->_type = other._type;
    std::cout << BG << "WrongCat copy constructor called\n" << RST;
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
    std::cout << BR << "WrongCat destructor called\n" << RST;
}
void WrongCat::makeSound() const
{
    std::cout << BB << "Meow\n" << RST;
}