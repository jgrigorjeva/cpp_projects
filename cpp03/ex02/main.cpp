#include "FragTrap.hpp"

int main()
{
    FragTrap serena("Serena");
    FragTrap bob(serena);
    FragTrap tom = bob;

    serena.attack("Bob");
    // serena.guardGate();
    serena.takeDamage(50);
    serena.beRepaired(20);
    serena.highFivesGuys();
    
}