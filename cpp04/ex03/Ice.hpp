#ifndef ICE
#define ICE

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
    public:
        Ice();
        Ice(std::string type);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif