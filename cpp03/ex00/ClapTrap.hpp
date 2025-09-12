#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hit_points;
        int _energy_points;
        int _attack_damage;
    public:
        // constructors
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage);
        ClapTrap(const ClapTrap& other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();
        // functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif