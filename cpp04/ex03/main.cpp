#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ground.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Colors.hpp"
#include <iostream>
#include <sstream>

int	main(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	// src->learnMateria(new Ice()); //should not be learned
	// src->learnMateria(new Cure()); //should not be learned
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	std::cout << BR << "*** this ***\n" << RST;

	me->equip(tmp);
	std::cout << "*** this ***\n";
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);

	std::cout << BOLD << "\n*** Checking that inventory only has 4 slots ***\n" << RST;
	for (int i = 0; i < 6; i++)
	{
		std::ostringstream s;
		s<<i;
		std::cout << BOLD << "round nr. " << s.str() << std::endl << RST;
		tmp = src->createMateria("cure");
		bob->equip(tmp);
	}

	std::cout << BOLD << "\n*** Test unequip(i) - Drop some materia from bob's inventory ***\n" << RST;
	for (int i = 0; i < 6; i++)
	{
		std::ostringstream s;
		s<<i;
		std::cout << BOLD << "round nr. " << s.str() << std::endl << RST;
		bob->unequip(i);
		if (i >= 4)
			std::cout << "testing unequip(i) with invalid i\n";
	}

	std::cout << BOLD << "\n*** Trying to equip a pointer to materia used before ***\n" << RST;
	bob->equip(tmp);

	std::cout << BOLD << "\n*** Test invalid use() ***\n" << RST;
	ICharacter *you = new Character("you");
	you->use(1, *me);
	you->equip(tmp);

	delete you;
	delete bob;
	delete me;
	delete src;
	return (0);
}