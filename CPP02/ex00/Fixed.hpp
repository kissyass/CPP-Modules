/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:49:50 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/02 19:49:45 by ykissiko         ###   ########.fr       */
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
};

#endif

