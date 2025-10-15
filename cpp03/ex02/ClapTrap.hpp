#ifndef CLAPTRAP
#define CLAPTRAP

#include <iostream>

class ClapTrap
{
    protected:
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
        // // getters
        // std::string get_name();
        // int get_hit_points();
        // int get_energy_points();
        // int get_attack_damage();
        // // setters
        // void set_name(std::string);
        // void set_hit_points(int);
        // void set_energy_points(int);
        // void set_attack_damage(int);
};

#endif