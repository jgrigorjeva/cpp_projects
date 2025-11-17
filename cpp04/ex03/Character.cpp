#include "Character.hpp"
#include "Colors.hpp"

Character::Character()
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    // std::cout << G << "Character default constructor\n" << RST;
}
Character::Character(const std::string name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    _name = name;
    // std::cout << G << "Character parametrized constructor\n" << RST;
}
Character::Character(const Character &other)
{
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
    }
    // std::cout << G << "Character copy constructor\n" << RST;    
}
Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
            inventory[i] = NULL;
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        }
    }
    // std::cout << G << "Character copy assignment operator\n" << RST;
	return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
    // std::cout << BR << "Character destructor\n" << RST;
}

// members overwrite

std::string const & Character::getName() const
{
    return (_name);
}

// zmenit logiku pro pripad, ze m je ulozeno u jineho uzivatele
void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << R << "Nonexistent materia!\n" << RST;
        return;
    }

    if (m->get_was_equipped())
    {
        std::cout << R << "This materia cannot be equipped\n" << RST;
        return; // don’t equip same pointer twice
    }
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            std::cout << "Materia of type " << m->getType() << " equipped\n";
            m->set_was_equipped();
            return ;
        }

    }
    // delete m;
    // m = NULL;
    _personalGround.storeMateria(m);
    m->set_was_equipped();
    std::cout << R << "Materia was not equipped\n"<< RST;
}
void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || !inventory[idx])
    {
        std::cout << R << "could not use inventory on " << target.getName() << RST << std::endl;
        return ;
    }
    inventory[idx]->use(target);
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3 || !inventory[idx])
        return ; 
    _personalGround.storeMateria(inventory[idx]);
    inventory[idx] = NULL;
    
}