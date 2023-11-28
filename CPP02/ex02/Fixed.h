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

//      Comparison operators
        bool operator>(Fixed const &rhs) const;
        bool operator<(Fixed const &rhs) const;
        bool operator>=(Fixed const &rhs) const;
        bool operator<=(Fixed const &rhs) const;
        bool operator==(Fixed const &rhs) const;
        bool operator!=(Fixed const &rhs) const;

//      Arithmetic operators
        Fixed operator+(Fixed const &rhs) const;
        Fixed operator-(Fixed const &rhs) const;
        Fixed operator*(Fixed const &rhs) const;
        Fixed operator/(Fixed const &rhs) const;

//      Increment/decrement
        Fixed &  operator++( void ); // prefix
        Fixed operator++( int ); // postfix
        Fixed &  operator--( void ); // prefix
        Fixed operator--( int ); // postfix

// MIN AND MAX
        static Fixed & min(Fixed &one, Fixed &two);
        static const Fixed & min(Fixed const &one, Fixed const &two);
        static Fixed & max(Fixed &one, Fixed &two);
        static const Fixed & max(Fixed const &one, Fixed const &two);
};

std::ostream & operator<<( std::ostream &o, Fixed const &a );

#endif