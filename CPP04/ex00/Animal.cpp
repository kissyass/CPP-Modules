/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:07:13 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 16:21:08 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal :: Animal(void)
{
    std::cout << "Default constructor from Animal class is called" << std::endl;
    
    this->_type = "Animal";
}
Animal :: Animal(Animal const &copy)
{
    std::cout << "Copy constructor from Animal class is called" << std::endl;
    
    *this = copy;
}

Animal & Animal :: operator=(Animal const &rhs)
{
    std::cout << "Copy operator from Animal class is called" << std::endl;
    
    if (this != &rhs)
        this->_type = rhs._type;

    return *this;
}

Animal :: ~Animal(void)
{
    std::cout << "Destructor from Animal class is called" << std::endl;
}

void Animal :: makeSound(void) const
{
    std::cout << "This animal makes some weird noise" << std::endl;
}

std::string Animal :: getType(void) const
{
    return this->_type;
}