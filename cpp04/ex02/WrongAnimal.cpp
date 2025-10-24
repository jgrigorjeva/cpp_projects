#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << G<< "WrongAnimal default constructor\n" << RST;
}
WrongAnimal::WrongAnimal(std::string type): _type(type)
{
    std::cout << G <<"WrongAnimal parametrized constructor\n" << RST;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other): _type(other._type)
{
    std::cout << G<< "WrongAnimal copy constructor\n" << RST;
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
    std::cout << R << "WrongAnimal destructor\n" << RST;
}

// methods
std::string WrongAnimal::getType() const
{
    return (_type);
}
void WrongAnimal::makeSound() const
{
    std::cout << B << "Generic WrongAnimal sound\n" << RST;
}