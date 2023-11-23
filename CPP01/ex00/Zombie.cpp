#include "Zombie.h"

Zombie :: Zombie()
{
    this->_name = "default zombie";
}

Zombie :: Zombie(std::string name)
{
    this->_name = name;
}

Zombie :: ~Zombie()
{
    std::cout << this->_name << " is now dead" << std::endl;
}

void Zombie :: announce()
{
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
