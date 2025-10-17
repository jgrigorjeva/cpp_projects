#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor\n";
}
Animal::Animal(std::string type): _type(type)
{
    std::cout << "Animal parametrized constructor\n";
}
Animal::Animal(const Animal& other): _type(other._type)
{
    std::cout << "Animal copy constructor\n";
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
    std::cout << "Animal destructor\n";
}

// methods
std::string Animal::getType()
{
    return (_type);
}
void Animal::makeSound()
{
    std::cout << "Generic animal sound\n";
}