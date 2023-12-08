/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:21:16 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 16:34:50 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog :: Dog(void)
{
    std::cout << "Default constructor from Dog class is called" << std::endl;
    
    this->_type = "Dog";
    this->brain = new Brain();
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
    {
        this->_type = rhs._type;
        this->brain = new Brain(*rhs.brain);
    }

    return *this;
}

Dog :: ~Dog(void)
{
    std::cout << "Destructor from Dog class is called" << std::endl;

    delete this->brain;
}

void Dog :: makeSound(void) const
{
    std::cout << "Bark" << std::endl;
}

std::string Dog :: getType(void) const
{
    return this->_type;
}

std::string Dog :: getIdea(int i) const
{
    return this->brain->getIdea(i);
}