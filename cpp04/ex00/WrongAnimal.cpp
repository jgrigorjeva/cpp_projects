#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor\n";
}
WrongAnimal::WrongAnimal(std::string type): _type(type)
{
    std::cout << "WrongAnimal parametrized constructor\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal& other): _type(other._type)
{
    std::cout << "WrongAnimal copy constructor\n";
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignment constructor\n";
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor\n";
}

// methods
std::string WrongAnimal::getType() const
{
    return (_type);
}
void WrongAnimal::makeSound() const
{
    std::cout << "Generic WrongAnimal sound\n";
}