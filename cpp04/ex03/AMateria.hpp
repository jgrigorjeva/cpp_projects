#ifndef AMATERIA
#define AMATERIA

// #include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
		std::string _type;
		bool		_was_equipped;
    public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		bool get_was_equipped();
		void set_was_equipped();
};
#endif