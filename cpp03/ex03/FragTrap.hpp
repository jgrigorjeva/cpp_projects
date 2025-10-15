#ifndef FRAGTRAP
#define FRAGTRAP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string);
        FragTrap(const FragTrap &other);
        FragTrap &operator=(const FragTrap &other);
        ~FragTrap();
        // methods
        void highFivesGuys(void);

};

#endif