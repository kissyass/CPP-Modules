/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:15:20 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/03 19:41:28 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie :: Zombie(void)
{
    this->_name = "Defaulty";
}

Zombie :: Zombie(std::string name) : _name(name)
{
}

Zombie :: ~Zombie(void)
{
    std::cout << this->_name << " is dead" << std::endl;
}

void Zombie :: announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie :: set_name(std::string name)
{
    this->_name = name;
}