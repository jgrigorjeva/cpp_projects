#include "Character.hpp"
#include "Colors.hpp"

Character::Character()
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    std::cout << G << "Character default constructor\n" << RST;
}
Character::Character(const std::string name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    _name = name;
    std::cout << G << "Character parametrized constructor\n" << RST;
}
Character::Character(const Character &other)
{
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
    }
    std::cout << G << "Character copy constructor\n" << RST;    
}
Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
            inventory[i] = NULL;
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        }
    }
    std::cout << G << "Character copy assignment operator\n" << RST;
	return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
    std::cout << BR << "Character destructor\n" << RST;
}