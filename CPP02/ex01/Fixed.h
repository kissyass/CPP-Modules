#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _num;
        static const int _bits = 8;
    public:
        Fixed();
        Fixed(Fixed const &copy);
        Fixed (const int num);
        Fixed (const float num);
        Fixed & operator=(Fixed const &rhs);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream & operator<<( std::ostream &o, Fixed const &a );

#endif