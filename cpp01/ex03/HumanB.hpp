#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"
#include <iostream>


class HumanB
{
    private:
        std::string _name;
        Weapon* _weapon;
    public:
        HumanB(std::string);
        ~HumanB();
        void setWeapon(Weapon&);
        void attack();

};

#endif