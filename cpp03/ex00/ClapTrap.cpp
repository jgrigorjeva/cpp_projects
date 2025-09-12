#include "ClapTrap.hpp"

//constructors
ClapTrap::ClapTrap(): _hit_points(10), _energy_points(10), _attack_damage(0)
{}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{

}


ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage): 
_name(name), _hit_points(hit_points), _energy_points(energy_points), _attack_damage(attack_damage)
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
    if (this->_hit_points <= 0 || this->_energy_points <= 0)
        return ;
    std::cout<< "ClapTrap " << this->_name << " attacks " << target << " , causing " << this->_attack_damage << " points of damage!\n";
    (this->_energy_points)--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    (this->_hit_points) -= amount;
    std::cout<< "ClapTrap " << this->_name << " takes damage, losing " << amount << " hit points!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_points <= 0)
        return ;
    (this->_hit_points) += amount;
    (this->_energy_points)++;
    std::cout<< "ClapTrap " << this->_name << " is repaired, gaining " << amount << " hit points!\n";
}