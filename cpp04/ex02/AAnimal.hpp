#ifndef AANIMAL
#define AANIMAL

#include <iostream>
#include "Colors.hpp"

// the AAnimal is an abstract class because it has at least one pure virtual function
// A pure virtual function is a virtual function whose declarator has the following syntax: 
//      declarator virt-specifier ﻿(optional) = 0 	
// In this case, pure virtual function is:
//       virtual void makeSound() const = 0;
// An abstract class cannot be instantiated, but pointers and references to the abstract class can be created

class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal& other);
        AAnimal &operator=(const AAnimal& other);
        virtual ~AAnimal();
        // methods
        std::string getType() const;
        virtual void makeSound() const = 0;
        // my additions to be used in derived classes
        virtual void set_idea(int index, std::string idea){(void)index, (void)idea;};
        virtual std::string get_idea(int index) const { (void)index; return NULL; };

};

#endif