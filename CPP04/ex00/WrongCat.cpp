/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:43:00 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 16:21:20 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat :: WrongCat(void)
{
    std::cout << "Default constructor from WrongCat class is called" << std::endl;
    
    this->_type = "WrongCat";
}
WrongCat :: WrongCat(WrongCat const &copy)
{
    std::cout << "Copy constructor from WrongCat class is called" << std::endl;
    
    *this = copy;
}

WrongCat & WrongCat :: operator=(WrongCat const &rhs)
{
    std::cout << "Copy operator from WrongCat class is called" << std::endl;
    
    if (this != &rhs)
        this->_type = rhs._type;

    return *this;
}

WrongCat :: ~WrongCat(void)
{
    std::cout << "Destructor from WrongCat class is called" << std::endl;
}

void WrongCat :: makeSound(void) const
{
   std::cout << "Meow" << std::endl;
}

std::string WrongCat :: getType(void) const
{
    return this->_type;
}