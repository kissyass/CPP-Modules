/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:02:35 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/04 15:46:15 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

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
    // std::cout << "getRawBits member function called" << std::endl;

    return this->_number;
}

void Fixed :: setRawbits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    
    this->_number = raw;
}

Fixed :: Fixed(const int num)
{
    this->_number = num << this->_bit;
    std::cout << "Int constructor called" << std::endl;
}

Fixed :: Fixed(const float num)
{
    this->_number = roundf(num * (1 << this->_bit));
    std::cout << "Float constructor called" << std::endl;
}

float Fixed :: toFloat(void) const
{
    return ((float)this->_number / (float)(1 << this->_bit));
}

int Fixed :: toInt(void) const
{
    return this->_number >> this->_bit;
}

std::ostream & operator<<(std::ostream &output, const Fixed &fixed)
{
    output << fixed.toFloat();
   
    return output;
}