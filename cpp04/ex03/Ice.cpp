#include "Ice.hpp"
#include "AMateria.hpp"
#include "Colors.hpp"

Ice::Ice()
{ 
	// std::cout << G << "Ice default constructor\n" << RST;
	_type = "ice";
}

Ice::Ice(std::string type)
{
	// std::cout << G << "Ice parametrized constructor\n" << RST;
	_type = "ice";
	(void)type;
}
Ice::Ice(const Ice &other): AMateria(other._type)
{
	// std::cout << G << "Ice copy constructor\n" << RST;
}
Ice &Ice::operator=(const Ice &other)
{
	_type = "ice";
	(void)other;
	// std::cout << G << "Ice copy assignment operator\n" << RST;
	return *this;
}

Ice::~Ice()
{
	// std::cout << R << "Ice destructor\n" << RST;
}
AMateria* Ice::clone() const
{
	Ice *clone = new Ice;
	std::cout << "Ice instance cloned\n";
	return clone;
}

void Ice::use(ICharacter& target)
{
	std::cout << BB << "* shoots an ice bolt at " << target.getName() << RST<<std::endl;
}