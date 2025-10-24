#include "Animal.hpp"

Animal::Animal()
{
    std::cout << G<<"Animal default constructor\n" << RST;
}
Animal::Animal(std::string type): _type(type)
{
    std::cout << G<<"Animal parametrized constructor\n" << RST;
}
Animal::Animal(const Animal& other): _type(other._type)
{
    std::cout <<  G<<"Animal copy constructor\n" << RST;
}
Animal &Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment constructor\n";
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << R << "Animal destructor\n" << RST;
}

// methods
std::string Animal::getType() const
{
    return (_type);
}
void Animal::makeSound() const
{
    std::cout << B << "Generic animal sound\n" << RST;
}