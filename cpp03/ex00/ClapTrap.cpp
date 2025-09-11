#include "ClapTrap.hpp"

//constructors
ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage): 
_name(name), _energy_points(energy_points), _attack_damage(attack_damage)
{

}
ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _hit_points(other._hit_points), 
_energy_points(other._energy_points), _attack_damage(other._attack_damage)
{

}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
	{
		this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
    }
	// std::cout << "Copy assignment operator called!" << std::endl;
	return (*this); 

}

ClapTrap::~ClapTrap(){}

// functions
void ClapTrap::attack(const std::string& target)
{
    std::cout<< "ClapTrap " << this->_name << " attacks " << target " , causing " this->_attack_damage << " points of damage!\n";
}
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);