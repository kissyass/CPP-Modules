/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:02:43 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/03 15:16:27 by ykissiko         ###   ########.fr       */
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
};

std::ostream & operator<<(std::ostream &output, const Fixed &fixed);

#endif

