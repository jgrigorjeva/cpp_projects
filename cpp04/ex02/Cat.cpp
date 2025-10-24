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
Cat::Cat(const Cat &other): AAnimal(other._type)
{
    this->_brain = new Brain(*other._brain);
    // for (int i=0; i < 100; i++)
    // {
    //     this->set_idea(i, other.get_idea(i));
    // }
    this->_type = other._type;
    std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &other)
{
    
    std::cout << "Cat copy assignment operator called\n";
    if (this != &other)
    {
        if (_brain)
            delete _brain;
        this->_brain = new Brain(*other._brain);
        // for (int i=0; i < 100; i++)
        // {
        //     this->set_idea(i, other.get_idea(i));
        // }
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

void Cat::set_idea(int index, std::string idea)
{
    _brain->set_idea(index, idea);
}

std::string Cat::get_idea(int index) const
{
    return (_brain->get_idea(index));
}