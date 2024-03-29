/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:50:27 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/03 19:41:56 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB :: HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = NULL;
}

HumanB :: ~HumanB(void)
{
}

void HumanB :: setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB :: attack(void) const
{
    if (this->_weapon == NULL)
        std::cout << this->_name << " doesn't have any weapon to attack" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
