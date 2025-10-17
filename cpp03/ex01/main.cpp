#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    std::cout<<"\n*** Constructors ***\n";
    ScavTrap serena("Serena");
    ScavTrap bob(serena);
    ScavTrap tom = bob;

    // serena.attack("Bob");
    // serena.guardGate();
    // serena.takeDamage(50);
    // serena.beRepaired(20);

    std::cout<<"\n*** Fight ***\n";
    for (int i = 0; i < 11; i++)
    {
        std::cout << "*** round " << i << std::endl;
        serena.attack("Bob");
        bob.takeDamage(20);
        bob.beRepaired(3);
        bob.attack("John");
        bob.attack("Serena");
        serena.takeDamage(20);
    }
    std::cout<<"\n*** guard mode ***\n";
    bob.guardGate();
    std::cout<<"\n*** Destructors ***\n";
}