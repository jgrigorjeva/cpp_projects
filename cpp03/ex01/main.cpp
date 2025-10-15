#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    ScavTrap serena("Serena");
    ScavTrap bob(serena);
    ScavTrap tom = bob;

    serena.attack("Bob");
    serena.guardGate();
    serena.takeDamage(50);
    serena.beRepaired(20);
    
}