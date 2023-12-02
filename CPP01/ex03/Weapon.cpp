/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:34:53 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/02 16:34:55 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon :: Weapon(void)
{
}

Weapon :: Weapon(std::string type) : _type(type)
{
}

Weapon :: ~Weapon(void)
{
}

const std::string & Weapon :: getType(void)
{
    return this->_type;
}

void Weapon :: setType(std::string type)
{
    this->_type = type;
}
