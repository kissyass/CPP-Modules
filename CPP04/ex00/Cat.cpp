/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:19:19 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 16:20:58 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat :: Cat(void)
{
    std::cout << "Default constructor from Cat class is called" << std::endl;
    
    this->_type = "Cat";
}
Cat :: Cat(Cat const &copy)
{
    std::cout << "Copy constructor from Cat class is called" << std::endl;
    
    *this = copy;
}

Cat & Cat :: operator=(Cat const &rhs)
{
    std::cout << "Copy operator from Cat class is called" << std::endl;
    
    if (this != &rhs)
        this->_type = rhs._type;

    return *this;
}

Cat :: ~Cat(void)
{
    std::cout << "Destructor from Cat class is called" << std::endl;
}

void Cat :: makeSound(void) const
{
   std::cout << "Meow" << std::endl;
}

std::string Cat :: getType(void) const
{
    return this->_type;
}