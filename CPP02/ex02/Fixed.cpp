/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:35:30 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/03 18:09:41 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed(void)
{
    // std::cout << "Default constructor called" << std::endl;
    this->_number = 0;
}

Fixed :: Fixed(Fixed const &copy)
{
    // std::cout << "Copy constructor called" << std::endl;

    this->_number = copy.getRawBits();
}

Fixed & Fixed :: operator=(Fixed const &rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;

    this->_number = rhs.getRawBits();

    return *this;
}

Fixed :: ~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed :: getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;

    return this->_number;
}

void Fixed :: setRawbits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    
    this->_number = raw;
}

Fixed :: Fixed(const int num)
{
    this->_number = num << this->_bit;
    // std::cout << "Int constructor called" << std::endl;
}

Fixed :: Fixed(const float num)
{
    this->_number = roundf(num * (1 << this->_bit));
    // std::cout << "Float constructor called" << std::endl;
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

/*===========================Comparison operators===========================*/

bool Fixed :: operator>(Fixed const &rhs) const
{
    return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed :: operator<(Fixed const &rhs) const
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed :: operator>=(Fixed const &rhs) const
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed :: operator<=(Fixed const &rhs) const
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed :: operator==(Fixed const &rhs) const
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed :: operator!=(Fixed const &rhs) const
{
    return (this->getRawBits() != rhs.getRawBits());
}

/*===========================Arithmetic operators===========================*/

Fixed Fixed :: operator+(Fixed const &rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed :: operator-(Fixed const &rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed :: operator*(Fixed const &rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed :: operator/(Fixed const &rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

/*===========================Increment/dectrement operators===========================*/
Fixed & Fixed :: operator++()
{
    this->_number++;
    return *this;
}

Fixed Fixed :: operator++(int)
{
    Fixed tmp(*this);
    this->_number++;
    return tmp;
}

Fixed & Fixed :: operator--()
{
    this->_number--;
    return *this;
}

Fixed Fixed :: operator--(int)
{
    Fixed tmp(*this);
    this->_number--;
    return tmp;
}

Fixed & Fixed :: min(Fixed &fix1, Fixed &fix2)
{
    if (fix1 < fix2)
        return fix1;
    return fix2;
}
const Fixed & Fixed :: min(Fixed const &fix1, Fixed const &fix2)
{
    if (fix1 < fix2)
        return fix1;
    return fix2;
}

Fixed & Fixed :: max(Fixed &fix1, Fixed &fix2)
{
    if (fix1 > fix2)
        return fix1;
    return fix2;
}

const Fixed & Fixed :: max(Fixed const &fix1, Fixed const &fix2)
{
    if (fix1 > fix2)
        return fix1;
    return fix2;
}