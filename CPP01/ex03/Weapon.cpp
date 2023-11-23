#include "Weapon.h"

const std::string &Weapon ::getType(void)
{
    return this->_type;
} 

void Weapon :: setType(std::string type)
{
    this->_type = type;
}

Weapon :: Weapon()
{
}

Weapon :: Weapon(std::string type)
{
    this->_type = type;
}

Weapon :: ~Weapon()
{
}
