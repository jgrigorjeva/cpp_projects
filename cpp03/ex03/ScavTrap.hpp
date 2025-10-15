#ifndef SCAVTRAP
#define SCAVTRAP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        ~ScavTrap();
        // members
        ScavTrap &operator = (const ScavTrap &other);
        void attack(const std::string& target);
        void guardGate();
};
#endif