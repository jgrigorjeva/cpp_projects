#ifndef CAT
#define CAT

#include "Animal.hpp"
#include "Colors.hpp"

class Cat : public Animal
{
    // in c++11, it is possible to inherit constructors like this:
    // Animal::Animal;
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        ~Cat();
        // members
        void makeSound() const;
};
#endif