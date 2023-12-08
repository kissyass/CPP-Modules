/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:29:49 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/07 12:24:38 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap :: FragTrap(void)
{
    std::cout << "Default constructor for FragTrap is called" << std::endl;
    
    this->_name = "FragTrapDef";
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    this->_max_hp = 100;
}

FragTrap :: FragTrap(FragTrap const &copy)
{
    std::cout << "Copy constructor for FragTrap is called" << std::endl;

    *this = copy;
}

FragTrap & FragTrap :: operator=(FragTrap const &rhs)
{
    std::cout << "Copy operator for FragTrap is called" << std::endl;

    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hit_points = rhs._hit_points;
        this->_energy_points = rhs._energy_points;
        this->_attack_damage = rhs._attack_damage;
        this->_max_hp = rhs._max_hp;
    }

    return *this;
}

FragTrap :: ~FragTrap(void)
{
    std::cout << "Destructor from FragTrap is called" << std::endl;
}

FragTrap :: FragTrap(std::string name)
{
    std::cout << "Constructor from FragTrap is called. ";
    
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    this->_max_hp = 100;

    std::cout << " Assigned name is " << this->_name << std::endl;
}

void FragTrap :: highFivesGuys(void)
{
    if (this->_hit_points > 0)
        std::cout << this->_name << " gives High Five" << std::endl;
}