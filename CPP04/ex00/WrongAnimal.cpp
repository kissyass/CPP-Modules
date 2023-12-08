/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:40:47 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 16:21:16 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal :: WrongAnimal(void)
{
    std::cout << "Default constructor from WrongAnimal class is called" << std::endl;
    
    this->_type = "WrongAnimal";
}
WrongAnimal :: WrongAnimal(WrongAnimal const &copy)
{
    std::cout << "Copy constructor from WrongAnimal class is called" << std::endl;
    
    *this = copy;
}

WrongAnimal & WrongAnimal :: operator=(WrongAnimal const &rhs)
{
    std::cout << "Copy operator from WrongAnimal class is called" << std::endl;
    
    if (this != &rhs)
        this->_type = rhs._type;

    return *this;
}

WrongAnimal :: ~WrongAnimal(void)
{
    std::cout << "Destructor from WrongAnimal class is called" << std::endl;
}

void WrongAnimal :: makeSound(void) const
{
    std::cout << "This WrongAnimal makes some weird noise" << std::endl;
}

std::string WrongAnimal :: getType(void) const
{
    return this->_type;
}