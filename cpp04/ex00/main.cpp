#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal* i = new Dog();
	const Animal *j = new Cat();
    const WrongAnimal *k = new WrongCat();
    // Cat cat;

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
   	std::cout << k->getType() << " " << std::endl;
    
	i->makeSound(); // will output the dog sound!
	j->makeSound();
    k->makeSound();
	meta->makeSound();
    // std::cout << cat.getType() << std::endl;
    // cat.makeSound();

    delete meta;
    delete i;
	delete j;
    delete k;
}