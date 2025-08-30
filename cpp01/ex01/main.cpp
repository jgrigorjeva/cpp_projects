#include "Zombie.hpp"

int main()
{
    std::string name = "deadPete";
    int num = 10;
    Zombie* horde = zombieHorde(num, name);
    for (int i = 0; i < num; i++ )
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}