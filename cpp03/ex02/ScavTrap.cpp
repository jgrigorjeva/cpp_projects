#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Scav default constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 20;
    std::cout << "Scav parametrized constructor is called with the name " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) 
{
    std::cout << "Scav copy constructor called\n";
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
     if (this != &other)
	{
		this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
    }
	std::cout << "Scav copy assignment operator called!" << std::endl;
	return (*this);
}

// destructor
ScavTrap::~ScavTrap()
{
    std::cout << "Scav destructor called" << std::endl;   
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hit_points <= 0 || this->_energy_points <= 0)
    {
        std::cout << "Too weak or injured. Can't attack.\n";
        return ;
    }
    std::cout<< "ScavpTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!\n";
    _energy_points = _energy_points - 1;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n";
}