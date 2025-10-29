#include "Colors.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		s_inventory[i] = NULL;
	// std::cout << G << "MateriaSource default constructor\n" << RST;
}
// MateriaSource::MateriaSource(const std::string name)
// {
// 	for (int i = 0; i < 4; i++)
// 		s_inventory[i] = NULL;
// 	_name = name;
// 	std::cout << G << "MateriaSource parametrized constructor\n" << RST;
// }
MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		s_inventory[i] = NULL;
		if (other.s_inventory[i])
			s_inventory[i] = other.s_inventory[i]->clone();
	}
	// std::cout << G << "MateriaSource copy constructor\n" << RST;
}
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (s_inventory[i])
			{
				delete s_inventory[i];
				s_inventory[i] = NULL;
			}
			
			if (other.s_inventory[i])
				s_inventory[i] = other.s_inventory[i]->clone();
		}
	}
	// std::cout << G << "MateriaSource copy assignment operator\n" << RST;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (s_inventory[i])
			delete s_inventory[i];
	}
	// std::cout << BR << "MateriaSource destructor\n" << RST;
}

// members overwrite
void MateriaSource::learnMateria(AMateria *source)
{
	for (int i = 0; i < 4; i++)
	{
		if (!s_inventory[i])
		{
			s_inventory[i] = source;
			std::cout << "new materia of type " << s_inventory[i]->getType() << " learned\n";
			return ;
		}
	}
	delete source;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	// AMateria *materia = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (s_inventory[i] && s_inventory[i]->getType() == type)
		{
			// materia = s_inventory[i]->clone();
			std::cout << "new materia of type " << type << " created\n";
			return s_inventory[i]->clone();
		}
	}
	return NULL;
}