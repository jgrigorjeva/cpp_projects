#ifndef WRONG_ANIMAL
#define WRONG_ANIMAL

#include <iostream>
#include "Colors.hpp"

// the destructor has to be virtual, otherwise:
// "deleting object of polymorphic class type ‘Animal’ which has non-virtual destructor might cause undefined behavior"
// If the destructor is non-virtual, only the WrongAnimal destructor will be called 

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal &operator=(const WrongAnimal& other);
        ~WrongAnimal();
        // methods
        std::string getType() const;
        void makeSound() const;

};

#endif