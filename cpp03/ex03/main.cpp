#include "DiamondTrap.hpp"

int main()
{
    std::cout<<"\n*** Constructors ***\n";
    DiamondTrap serena("Serena");
    DiamondTrap bob(serena);
    DiamondTrap tom = bob;

    std::cout<<"\n*** Fight ***\n";
    for (int i = 0; i < 11; i++)
    {
        std::cout << "*** round " << i << std::endl;
        serena.attack("Bob");
        bob.takeDamage(30);
        bob.beRepaired(3);
        bob.attack("John");
        bob.attack("Serena");
        serena.takeDamage(30);
    }
    std::cout<<"\n*** high five mode ***\n";
    serena.highFivesGuys();

    std::cout<<"\n*** guard mode ***\n";
    serena.guardGate();

    std::cout<<"\n*** who am I mode ***\n";
    serena.whoAmI();
    std::cout<<"\n*** Destructors ***\n";
}