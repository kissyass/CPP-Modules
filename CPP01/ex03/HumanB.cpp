// // Now, create two classes: HumanA and HumanB. 
// // They both have a Weapon and a name. 
// // They also have a member function attack() that displays (of course, without the angle brackets):
// //     <name> attacks with their <weapon type>
// // HumanA and HumanB are almost the same except for these two tiny details: 
// // • While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// // • HumanB may not always have a Weapon, whereas HumanA will always be armed.

// #ifndef HUMAN_B_H
// #define HUMAN_B_H

// #include "HumanA.h"

// class HumanB
// {
//     private:
//         std::string _name;
//         Weapon *_weapon;
//     public:
//         HumanB();
//         ~HumanB();
//         void setWeapon(Weapon &weapon);
//         void attack();
// }

// #endif

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