#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"
#include "Brain.hpp"
#include <iostream>
#include <sstream>

#define ANUM 10

int	main(void)
{
	Animal *animals[ANUM];
	Animal *copy_animals[ANUM];

	for (int i=0; i < ANUM; i++)
	{
		if (i%2)
		{
			std::ostringstream s;
			s<<i;
			std::string idea = "cat " + s.str() + " first idea";
			animals[i] = new Cat();
			animals[i]->makeSound();
			animals[i]->set_idea(0, idea);
			std::cout << BOLD << animals[i]->get_idea(0) << RST << std::endl;
			std::cout << BOLD << animals[i]->get_idea(1) << RST << std::endl;

		}
		else
		{
			std::ostringstream s;
			s<<i;
			std::string idea = "dog " + s.str() + " first idea";
			animals[i] = new Dog();
			animals[i]->makeSound();
			animals[i]->set_idea(0, idea);
			std::cout << BOLD << animals[i]->get_idea(0) << RST << std::endl;

		}	
	}

	std::cout << BR << "\n*** Copy animals ***\n\n" << RST;
	for (int i=0; i < ANUM; i++)
	{
		if (i%2)
		{
			// the *dynamic_cast<Cat*> is necessary for the copy constructor, otherwise *animals[i] is of type Animal* and we need the type Cat* in the copy constructor
			copy_animals[i] = new Cat(*dynamic_cast<Cat*>(animals[i]));
			copy_animals[i]->makeSound();
			std::cout << BOLD << copy_animals[i]->get_idea(0) << RST << std::endl;

		}
		else
		{
			copy_animals[i] = new Dog(*dynamic_cast<Dog*>(animals[i]));
			copy_animals[i]->makeSound();
			std::cout << BOLD << copy_animals[i]->get_idea(0) << RST << std::endl;

		}	
	}


	for (int i=0; i <ANUM; i++)
	{
		delete animals[i];
		delete copy_animals[i];
	}
}