#include "Fixed.h"

Fixed :: Fixed()
{
    std::cout << "Default constructor called\n";

    this->_num = 0;
}

Fixed :: Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called\n";

    this->_num = copy.getRawBits();
}

Fixed :: Fixed(const int num) : _num(num << _bits)
{
    std::cout << "Int constructor called\n";
}

Fixed :: Fixed(const float num) : _num(std::roundf(num * (1 << _bits)))
{
    std::cout << "Float constructor called\n";
}

Fixed :: ~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignment operator called\n";

    this->_num = rhs.getRawBits();

    return *this;
}

int Fixed :: getRawBits(void) const
{
    // std::cout << "getRawBits member function called\n";
    return this->_num;
}

void Fixed :: setRawBits(int const raw)
{
    this->_num = raw;
}

float Fixed :: toFloat( void ) const
{
    return (float)this->_num / (1 << this->_bits);
}

int Fixed :: toInt( void ) const
{
    return this->_num >> this->_bits;
}

std::ostream & operator<<( std::ostream &o, Fixed const &a ) 
{
    o << a.toFloat();
    return o;
}