#ifndef CURE
#define CURE

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
    public:
        Cure();
        Cure(std::string type);
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif