#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap()
{
    std::cout << "Diamond default constructor called\n";
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
    std::cout << "Diamond parametrized constructor called\n";
    this->_name = name;
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "Diamond copy constructor called\n";

}
// DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other);

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond destructor called\n";
}