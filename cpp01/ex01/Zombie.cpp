#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){}

Zombie::Zombie(std::string name)
{
    // std::cout << "default constructor" << std::endl;
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << "Destroyed: " << _name << std::endl;
}

void Zombie::announce(void)
{
    std::string message = ": BraiiiiiiinnnzzzZ...";
    std::cout << _name << ": " << message << std::endl;
}
