#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << G<<"AAnimal default constructor\n" << RST;
}
AAnimal::AAnimal(std::string type): _type(type)
{
    std::cout << G<<"AAnimal parametrized constructor\n" << RST;
}
AAnimal::AAnimal(const AAnimal& other): _type(other._type)
{
    std::cout <<  G<<"AAnimal copy constructor\n" << RST;
}
AAnimal &AAnimal::operator=(const AAnimal& other)
{
    std::cout << "AAnimal copy assignment constructor\n";
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << R << "AAnimal destructor\n" << RST;
}

// methods
std::string AAnimal::getType() const
{
    return (_type);
}
void AAnimal::makeSound() const
{
    std::cout << B << "Generic AAnimal sound\n" << RST;
}