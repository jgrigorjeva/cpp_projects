#include "Cure.hpp"
#include "AMateria.hpp"
#include "Colors.hpp"

Cure::Cure()
{ 
	// std::cout << G << "Cure default constructor\n" << RST;
	_type = "cure";
}

Cure::Cure(std::string type)
{
	// std::cout << G << "Cure parametrized constructor\n" << RST;
	_type = "cure";
	(void)type;
}
Cure::Cure(const Cure &other): AMateria(other._type)
{
	// _type = other._type;
	// std::cout << G << "Cure copy constructor\n" << RST;
}
Cure &Cure::operator=(const Cure &other)
{
	_type = "cure";
	// std::cout << G << "Cure copy assignment operator\n" << RST;
	(void)other;
	return *this;
}

Cure::~Cure()
{
	// std::cout << R << "Cure destructor\n" << RST;
}
AMateria* Cure::clone() const
{
	Cure *clone = new Cure;
	std::cout  << "Cure instance cloned\n";
	return clone;
}

void Cure::use(ICharacter& target)
{
	std::cout << BG<< "* heals " << target.getName() << "'s wounds *" << RST<<std::endl;
}