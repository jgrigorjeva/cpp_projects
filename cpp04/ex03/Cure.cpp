#include "Cure.hpp"
#include "AMateria.hpp"
#include "Colors.hpp"

Cure::Cure()
{ 
	std::cout << G << "Cure default constructor\n" << RST;
	_type = "Cure";
}

Cure::Cure(std::string type)
{
	std::cout << G << "Cure parametrized constructor\n" << RST;
	_type = "Cure";
	(void)type;
}
Cure::Cure(const Cure &other): Cure(other._type)
{
	std::cout << G << "Cure copy constructor\n" << RST;
}
Cure &Cure::operator=(const Cure &other)
{
	_type = "Cure";
	std::cout << G << "Cure copy assignment operator\n" << RST;
	return *this;
}

Cure::~Cure()
{
	std::cout << R << "Cure destructor\n" << RST;
}
AMateria* Cure::clone() const
{
	Cure clone("Cure");
	std::cout << BB << "Cure instance cloned\n" << RST;
	return &clone;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}