#ifndef DOG
#define DOG

#include "AAnimal.hpp"
#include "Colors.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    // in c++11, it is possible to inherit constructors like this:
    // Animal::Animal;
    private:
    Brain *_brain;
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        ~Dog();
        // members
        void makeSound() const;
        // my members
        void set_idea(int index, std::string idea);
        std::string get_idea(int index) const;
};
#endif