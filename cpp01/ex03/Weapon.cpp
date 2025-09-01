#include "Weapon.hpp"
Weapon::Weapon(){}

Weapon::Weapon(std::string type): _type(type)
{
    // this->_type = type; //reserve "this" for more complicated logic
}
Weapon::~Weapon(){}

std::string Weapon::getType() const
{
    return (_type);
}

void Weapon::setType(std::string new_val)
{
    _type = new_val;
}