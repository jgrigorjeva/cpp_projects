#ifndef ANIMAL
#define ANIMAL

#include <iostream>
#include "Colors.hpp"

// the destructor has to be virtual, otherwise:
// "deleting object of polymorphic class type ‘Animal’ which has non-virtual destructor might cause undefined behavior"
// If the destructor is non-virtual, only the Animal destructor will be called 

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& other);
        Animal &operator=(const Animal& other);
        virtual ~Animal();
        // methods
        std::string getType() const;
        virtual void makeSound() const;

};

#endif