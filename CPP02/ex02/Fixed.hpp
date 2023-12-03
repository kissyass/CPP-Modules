/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:35:27 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/03 18:06:42 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
    private:
        int _number;
        static const int _bit = 8;
    public:
        Fixed(void);
        Fixed(Fixed const &copy);
        Fixed & operator=(Fixed const &rhs);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawbits(int const raw);
        Fixed(const int num);
        Fixed(const float num);
        float toFloat(void) const;
        int toInt(void) const;
        /*=========Comparison operators=========*/
        bool operator>(Fixed const &rhs) const;
        bool operator<(Fixed const &rhs) const;
        bool operator>=(Fixed const &rhs) const;
        bool operator<=(Fixed const &rhs) const;
        bool operator==(Fixed const &rhs) const;
        bool operator!=(Fixed const &rhs) const;
        /*=========Arithmetic operators=========*/
        Fixed operator+(Fixed const &rhs) const;
        Fixed operator-(Fixed const &rhs) const;
        Fixed operator*(Fixed const &rhs) const;
        Fixed operator/(Fixed const &rhs) const;
        /*=========Increment/dectrement operators=========*/
        Fixed & operator++();
        Fixed operator++(int); // to allow the compiler to distinguish between the prefix and postfix forms of the operator.
        Fixed & operator--();
        Fixed operator--(int); // to allow the compiler to distinguish between the prefix and postfix forms of the operator.
        static Fixed & min(Fixed &fix1, Fixed &fix2);
        static const Fixed & min(Fixed const &fix1, Fixed const &fix2);
        static Fixed & max(Fixed &fix1, Fixed &fix2);
        static const Fixed & max(Fixed const &fix1, Fixed const &fix2);

};

std::ostream & operator<<(std::ostream &output, const Fixed &fixed);

#endif

