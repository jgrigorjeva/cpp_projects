#ifndef WRONG_CAT
#define WRONG_CAT

#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
    // in c++11, it is possible to inherit constructors like this:
    // Animal::Animal;
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat &other);
        WrongCat &operator=(const WrongCat &other);
        ~WrongCat();
        // members
        void makeSound() const;
};
#endif