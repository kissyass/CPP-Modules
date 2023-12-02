/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:15:20 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/02 16:15:37 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie :: Zombie(void)
{
    this->_name = "Defaulty";
}

Zombie :: Zombie(std::string name) : _name(name)
{
}

Zombie :: ~Zombie(void)
{
    std::cout << this->_name << " is dead\n";
}

void Zombie :: announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie :: set_name(std::string name)
{
    this->_name = name;
}