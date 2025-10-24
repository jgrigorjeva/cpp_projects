#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

int	main(void)
{
	std::cout << BOLD << "*** Correct animal implementation ***\n" << RST;
	const Animal *meta = new Animal();
	const Animal* i = new Dog();
	const Animal *j = new Cat();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
   	
    
	i->makeSound(); // will output the dog sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << BOLD << "*** Wrong animal implementation ***" << RST << std::endl;
	const WrongAnimal *k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();

	std::cout << BOLD << "*** Delete ***" << RST << std::endl;
    delete meta;
    delete i;
	delete j;
    delete k;
}