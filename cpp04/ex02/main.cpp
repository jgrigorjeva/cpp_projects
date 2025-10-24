#include "AAnimal.hpp"
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
	AAnimal *animals[ANUM]; // Pointers and references to an abstract class can be declared.  
	// AAnimal no_instance; // abstract class cannot be instantiated

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
			// std::cout << BOLD << animals[i]->get_idea(1) << RST << std::endl;

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

	// std::cout << BR << "\n*** Copy animals ***\n\n" << RST;
	// for (int i=0; i < ANUM; i++)
	// {
	// 	if (i%2)
	// 	{
	// 		// the *dynamic_cast<Cat*> is necessary for the copy constructor, otherwise *animals[i] is of type Animal* and we need the type Cat* in the copy constructor
	// 		copy_animals[i] = new Cat(*dynamic_cast<Cat*>(animals[i]));
	// 		copy_animals[i]->makeSound();
	// 		std::cout << BOLD << copy_animals[i]->get_idea(0) << RST << std::endl;

	// 	}
	// 	else
	// 	{
	// 		copy_animals[i] = new Dog(*dynamic_cast<Dog*>(animals[i]));
	// 		copy_animals[i]->makeSound();
	// 		std::cout << BOLD << copy_animals[i]->get_idea(0) << RST << std::endl;

	// 	}	
	// }

	std::cout << BR << "\n*** Testing copy constructor and copy assignment operator ***\n" << RST;
	Cat* copyCat =  new Cat(*dynamic_cast<Cat*>(animals[1]));
	Cat* assignCat = new Cat();
	*assignCat = *dynamic_cast<Cat*>(animals[1]);
	Dog* copyDog = new Dog(*dynamic_cast<Dog*>(animals[0]));
	Dog* assignDog = new Dog();
	*assignDog = *dynamic_cast<Dog*>(animals[0]);

	std::cout << BOLD<< "\n*** old ideas: original and new animals ***\n" << RST;
	std::cout << BOLD<< "original cat thought: " << RST<< animals[1]->get_idea(0) << std::endl;
	std::cout << "copy cat thought: " << copyCat->get_idea(0) << std::endl;
	std::cout << "assign cat thought: " << assignCat->get_idea(0) << std::endl;
	std::cout << BOLD<< "original dog thought: "<<RST << animals[0]->get_idea(0) << std::endl;
	std::cout << "copy dog thought: " << copyDog->get_idea(0) << std::endl;
	std::cout << "assign dog thought: " << assignDog->get_idea(0) << std::endl;

	std::cout << BOLD<< "\n*** new ideas: original and new animals ***\n" << RST;
	animals[1]->set_idea(0, "Eat tuna");
	animals[0]->set_idea(0, "Wag tail");
	std::cout << BOLD<< "original cat thought: " << RST<< animals[1]->get_idea(0) << std::endl;
	std::cout << "copy cat thought: " << copyCat->get_idea(0) << std::endl;
	std::cout << "assign cat thought: " << assignCat->get_idea(0) << std::endl;
	std::cout << BOLD<< "original dog thought: "<<RST << animals[0]->get_idea(0) << std::endl;
	std::cout << "copy dog thought: " << copyDog->get_idea(0) << std::endl;
	std::cout << "assign dog thought: " << assignDog->get_idea(0) << std::endl;



	for (int i=0; i <ANUM; i++)
	{
		delete animals[i];
	}
	std::cout << BOLD << "delete copied animals\n";
	delete copyCat;
	delete assignCat;
	delete copyDog;
	delete assignDog;
}