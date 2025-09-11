#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hit_points = 10;
        int _energy_points = 10;
        int _attack_damage = 0;
    public:
        // constructors
        ClapTrap();
        ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage);
        ClapTrap(const ClapTrap& other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();
        // functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
}
#endif