#ifndef CHARACTER
#define CHARACTER

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
    private:
    AMateria *inventory[4];
    std::string _name;
    public:
    Character();
	Character(const std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();
    // member overwrite
    void use(int idx, ICharacter& target);
    void unequip(int idx);

};

#endif