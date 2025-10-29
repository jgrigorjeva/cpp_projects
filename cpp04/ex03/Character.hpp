#ifndef CHARACTER
#define CHARACTER

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include "Ground.hpp"

class Character : public ICharacter
{
    private:
    AMateria *inventory[4];
    std::string _name;
    Ground _personalGround;
    public:
    Character();
	Character(const std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();
    // member overwrite
    std::string const & getName() const;
    void equip(AMateria* m);
    void use(int idx, ICharacter& target);
    void unequip(int idx);

};

#endif