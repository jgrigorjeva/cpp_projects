#ifndef DOG
#define DOG

#include "Animal.hpp"
class Dog : public Animal
{
    // in c++11, it is possible to inherit constructors like this:
    // Animal::Animal;
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        ~Dog();
        // members
        void makeSound() const;
};
#endif