#include "AMateria.hpp"
#include "Colors.hpp"

AMateria::AMateria()
{
	// std::cout << BG << "AMateria default constructor\n" << RST;
}
AMateria::AMateria(std::string const & type)
{
	// std::cout << BG << "AMateria parametrized constructor\n" << RST;
	_type = type;
}
AMateria::AMateria(const AMateria &other)
{
	_type = other._type;
	// std::cout << BG << "AMateria copy constructor\n" << RST;
}
AMateria &AMateria::operator=(const AMateria &other)
{
	// std::cout << G << "AMateria copy assignment operator\n" << RST;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

AMateria::~AMateria()
{
	// std::cout << BR << "AMateria destructor\n" << RST;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout  << "AMateria default use on" << target.getName() << std::endl;
}
