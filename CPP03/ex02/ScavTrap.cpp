/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:40:24 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/06 19:31:35 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

ScavTrap :: ScavTrap(void)
{
    std::cout << "Default constructor for ScavTrap is called" << std::endl;

    this->_name = "ScavTrapDef";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    this->_max_hp = 100;
}

ScavTrap :: ScavTrap(ScavTrap const &copy)
{
    std::cout << "Copy constructor for ScavTrap is called" << std::endl;
    *this = copy;
}

ScavTrap & ScavTrap :: operator=(ScavTrap const &rhs)
{
    std::cout << "Copy operator for ScavTrap is called" << std::endl;

    this->_name = rhs._name;
    this->_hit_points = rhs._hit_points;
    this->_energy_points = rhs._energy_points;
    this->_attack_damage = rhs._attack_damage;
    this->_max_hp = rhs._max_hp;
    
    return *this;
}

ScavTrap :: ~ScavTrap(void)
{
    std::cout << "Destructor for ScavTrap is called" << std::endl;
}

ScavTrap :: ScavTrap(std::string name)
{
    std::cout << "Constructor for ScavTrap is called";
    
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    this->_max_hp = 100;

    std::cout << ". Assigned name is " << this->_name << std::endl;
}

void ScavTrap :: attack(const std::string & target)
{
    if (this->_hit_points == 0)
        ;
    else if (this->_energy_points == 0)
        std::cout << this->_name << " from ScavTrap has no energy to attack" << std::endl;
    else
    {
        std::cout << this->_name << " from ScavTrap attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points--;
    }
}

void ScavTrap :: guardGate(void)
{
    if (this->_hit_points > 0)
       std::cout << this->_name << " from ScavTrap is now in a Gate Keeper Mode" << std::endl;
}
