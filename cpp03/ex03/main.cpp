#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap serena("Serena");
    DiamondTrap bob(serena);
    // DiamondTrap tom = bob;

    serena.attack("Bob");
    // serena.guardGate();
    serena.takeDamage(50);
    serena.beRepaired(20);
    serena.highFivesGuys();
    
}