#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Frag default constructor is called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "Frag parametrized constructor is called with the name " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
    std::cout << "Frag copy constructor is called" << std::endl;
    *this = other;
    // this->_name = other._name;
    // this->_attack_damage = other._attack_damage;
    // this->_energy_points = other._energy_points;
    // this->_hit_points = other._hit_points;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
	{
		this->_name = other._name;
        this->_attack_damage = other._attack_damage;
        this->_energy_points = other._energy_points;
        this->_hit_points = other._hit_points;
    }
	std::cout << "Frag copy assignment operator called!" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "Frag destructor called" << std::endl;   
}

void FragTrap::highFivesGuys(void)
{
    std::cout << _name << " says: give me high-fives, guys!\n";
}