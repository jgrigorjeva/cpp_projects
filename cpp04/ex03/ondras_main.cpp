/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ondras_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:55:48 by okraus            #+#    #+#             */
/*   Updated: 2025/10/29 15:43:10 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
// #include "Colours.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
        // bob->equip(tmp);
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		return 0;
	}
	{
		// MateriaSource learning
		// IMateriaSource* src = new MateriaSource();
		// AMateria	*ice1 = new Ice();

		// src->learnMateria(new Ice());
		// src->learnMateria(new Cure());
		// src->learnMateria(new Cure());
		// src->learnMateria(new Cure());
		// src->learnMateria(ice1);

		// delete ice1;
		// delete src;
	}
	{
		// Floor capacity
		// ICharacter	*john = new Character("John");
		// ICharacter	*ben = new Character("Ben");
		// AMateria *tmp_materia;

		// for (int i = 0; i < 200; i++)
		// {
		// 	tmp_materia = new Cure();
		// 	std::cout << i << ". " << std::endl;
		// 	john->equip(tmp_materia);
		// 	tmp_materia = new Ice();
		// 	john->equip(tmp_materia);
		// 	john->unequip(0);
		// 	john->unequip(1);
		// }
		// // Character::getFloor();
		// tmp_materia = new Cure();
		// ben->equip(tmp_materia);
		// ben->unequip(0);

		// delete john;
		// delete ben;
		// return 0;
	}
	{
//		// Character unequip, sweep floor and use
		// AMateria	*ice1 = new Ice();
		// AMateria	*ice2 = new Ice();
		// AMateria	*cure1 = new Cure();
		// AMateria	*cure2 = new Cure();
		// AMateria	*cure3 = new Cure();
		// ICharacter	*john = new Character("John");
		// ICharacter	*ben = new Character("Ben");

		// // Character::getFloor();
		// john->equip(ice1);
		// john->equip(ice2);
		// john->use(0, *ben);
		// john->use(4, *ben);
		// john->use(3, *ben);
		// john->equip(cure1);
		// john->equip(cure2);

		// john->unequip(1);

		// john->unequip(5);
		// john->unequip(-8);
		// john->unequip(2);

		// ben->equip(ice1);
		// ben->equip(ice2);
		// ben->equip(cure3);
		// ben->use(-5, *john);
		// ben->use(0, *john);
		// ben->use(1, *john);
		// delete john;
		// delete ben;
		// return 0;
	}
	{
		// Character equip limits
		// AMateria	*ice1 = new Ice();
		// AMateria	*ice2 = new Ice();
		// AMateria	*ice3 = new Ice();
		// AMateria	*ice4 = new Ice();
		// AMateria	*ice5 = new Ice();
		// ICharacter	*john = new Character("John");
		// ICharacter	*ben = new Character("Ben");

		// john->equip(ice1);
		// john->use(2, *ben);
		// john->equip(ice2);
		// john->equip(ice3);
		// john->equip(ice4);
		// john->equip(ice5);
		// john->use(2, *ben);
		// john->use(-2, *ben);
		// john->use(5, *ben);

		// delete john;
		// delete ben;
		// delete ice5;
		// return 0;
	}
	{
//		// Character copy constructor and assignment operator
		// AMateria	*ice1 = new Ice();
		// AMateria	*ice2 = new Ice();
		// AMateria	*ice3 = new Ice();
		// AMateria	*ice4 = new Ice();
		// Character	*john = new Character("John");

		// john->equip(ice1);
		// john->equip(ice2);
		// john->equip(ice3);
		// john->equip(ice4);
		// ICharacter	*ben = new Character(*john);

		// delete john;
		// delete ben;
		// return 0;
	}
	{
//		// AMateria and Ice constructors
		// Ice	*ice = new Ice();

		// std::cout << ice->getIsFresh() << std::endl;
		// ice->unsetFresh();
		// std::cout << ice->getIsFresh() << std::endl;

		// AMateria	*ice2 = new Ice(*ice);
		// std::cout << ice2->getIsFresh() << std::endl;
	

		// AMateria	*ice4 = new Ice();
		// AMateria	*ice3;
		// ice4->unsetFresh();
		// ice3 = ice4;
		// std::cout << ice3->getIsFresh() << std::endl;

		// delete ice;
		// delete ice2;
		// delete ice4;
		// return 0;
	}
}