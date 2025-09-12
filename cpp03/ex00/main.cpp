#include "ClapTrap.hpp"

int main()
{
    ClapTrap john("John");
    ClapTrap mark("Mark");
    ClapTrap john2(john);
    ClapTrap poor_pete("Pete", 1, 1, 1);

    for (int i = 0; i < 11; i++)
    {
        std::cout << "*** round " << i << std::endl;
        john.attack("Mark");
        mark.takeDamage(5);
        mark.beRepaired(3);
        mark.attack("John");
    }
    
}