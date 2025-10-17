#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap()
{
    std::cout << "Diamond default constructor called\n";
        std::cout << "my name is " << this->_name << std::endl;

    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
    std::cout << "Diamond parametrized constructor called\n";
    this->_name = name;
    std::cout << "my name is " << this->_name << std::endl;
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "Diamond copy constructor called\n";
    *this = other;
        std::cout << "my name is " << this->_name << std::endl;


}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "Diamond copy assignment operator called!" << std::endl;
    if (this != &other)
	{
		this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond destructor called\n";
}

// methods
void DiamondTrap::whoAmI()
{
    std::cout << "I am " << _name << ", and " << ClapTrap::_name << std::endl;
}