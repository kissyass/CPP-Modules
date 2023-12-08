/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:21:16 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 16:21:02 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog :: Dog(void)
{
    std::cout << "Default constructor from Dog class is called" << std::endl;
    
    this->_type = "Dog";
}
Dog :: Dog(Dog const &copy)
{
    std::cout << "Copy constructor from Dog class is called" << std::endl;
    
    *this = copy;
}

Dog & Dog :: operator=(Dog const &rhs)
{
    std::cout << "Copy operator from Dog class is called" << std::endl;
    
    if (this != &rhs)
        this->_type = rhs._type;

    return *this;
}

Dog :: ~Dog(void)
{
    std::cout << "Destructor from Dog class is called" << std::endl;
}

void Dog :: makeSound(void) const
{
    std::cout << "Bark" << std::endl;
}

std::string Dog :: getType(void) const
{
    return this->_type;
}