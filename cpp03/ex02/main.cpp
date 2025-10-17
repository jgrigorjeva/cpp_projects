#include "FragTrap.hpp"

int main()
{
    std::cout<<"\n*** Constructors ***\n";
    FragTrap serena("Serena");
    FragTrap bob(serena);
    FragTrap tom = bob;

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
    bob.highFivesGuys();
    std::cout<<"\n*** Destructors ***\n";
}