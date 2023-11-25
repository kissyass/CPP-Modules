#include "HumanB.h"

HumanB :: HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = NULL;
}

HumanB :: ~HumanB()
{
}

void HumanB :: setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB :: attack(void) const
{
    if (this->_weapon == NULL)
        std::cout << this->_name << " doesn't have any weapons\n";
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}