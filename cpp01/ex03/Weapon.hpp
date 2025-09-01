#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
    private:
        std::string _type;

    public:
        Weapon();
        Weapon(std::string);
        ~Weapon();
        std::string getType() const;
        void setType(std::string);

};

#endif