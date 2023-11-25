#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
    private:
        int _num;
        static const int _bits = 8;
    public:
        Fixed();
        Fixed(Fixed const &copy);
        Fixed & operator=(Fixed const &rhs);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif