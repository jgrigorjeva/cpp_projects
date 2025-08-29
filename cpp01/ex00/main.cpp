#include "Zombie.hpp"

int main(void)
{
    Zombie *newZombie1;
    newZombie1 = newZombie("Numero");
    newZombie1->announce();
    randomChump("Numero Uno");
    delete newZombie1;
    return (0);
}