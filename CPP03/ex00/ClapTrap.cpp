/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:28:13 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/06 19:28:31 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap :: ClapTrap(void) : _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Deafult constructor for ClapTrap is called" << std::endl;
    
    this->_name = "ClapTrapDef";
    this->_max_hp = 10;
}

ClapTrap :: ClapTrap(ClapTrap const &copy)
{
    std::cout << "Copy constructor for ClapTrap is called" << std::endl;
    
    *this = copy;
}

ClapTrap & ClapTrap :: operator=(ClapTrap const &rhs)
{
    std::cout << "Copy operator for ClapTrap is called" << std::endl;
    
    this->_name = rhs._name;
    this->_hit_points = rhs._hit_points;
    this->_energy_points = rhs._energy_points;
    this->_attack_damage = rhs._attack_damage;
    this->_max_hp = rhs._max_hp;
    
    return *this;
}

ClapTrap :: ~ClapTrap(void)
{
    std::cout << "Destructor for ClapTrap is called" << std::endl;
}

ClapTrap :: ClapTrap(std::string name) : _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Constructor for ClapTrap is called";
    this->_name = name;
    this->_max_hp = 10;
    std::cout << ". Assigned name is " << this->_name << std::endl;
}

void ClapTrap :: attack(const std::string & target)
{
    if (this->_hit_points == 0)
        ;
    else if (this->_energy_points == 0)
        std::cout << this->_name << " from ClapTrap has no energy to attack" << std::endl;
    else
    {
        std::cout << this->_name << " from ClapTrap attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points--;
    }
}

void ClapTrap :: takeDamage(unsigned int amount)
{
    if (this->_hit_points == 0)
        ;
    else if (this->_hit_points <= amount)
    {
        std::cout << this->_name << " from ClapTrap is dead now" << std::endl;
        this->_hit_points = 0;        
    }
    else
    {
        this->_hit_points -= amount;
        std::cout << this->_name << " from ClapTrap got attacked and lost " << amount << " hit points. Amount of hit points left: " << this->_hit_points << std::endl;
        if (this->_hit_points < this->_max_hp / 2)
            std::cout << "Get repaired fast or you will die" << std::endl;
    }
}

void ClapTrap :: beRepaired(unsigned int amount)
{
    if (this->_hit_points == 0)
        ;
    else if (this->_energy_points == 0)
        std::cout << this->_name << " from ClapTrap has no energy to be repaired" << std::endl;
    else
    {
        std::cout << "Repairing " << this->_name << " from ClapTrap ..." << std::endl;
        if (this->_hit_points + amount > this->_max_hp)
        {
            this->_hit_points = this->_max_hp;
            std::cout << "Cannot add " << amount << " hit points, the max is reached. Amount of hit points after repair: " << this->_hit_points << std::endl;
        }
        else
        {
            this->_hit_points += amount;
            std::cout << "Added " << amount << " hit points. Amount of hit points after repair: " << this->_hit_points << std::endl;
            this->_energy_points--; 
        }
    }
}