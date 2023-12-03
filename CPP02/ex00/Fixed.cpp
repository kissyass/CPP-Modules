/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:50:00 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/02 20:00:58 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->_number = 0;
}

Fixed :: Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;

    this->_number = copy.getRawBits();
}

Fixed & Fixed :: operator=(Fixed const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    this->_number = rhs.getRawBits();

    return *this;
}

Fixed :: ~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed :: getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;

    return this->_number;
}

void Fixed :: setRawbits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    
    this->_number = raw;
}