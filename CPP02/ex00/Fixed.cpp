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
    std::cout << "getRawBits member function called\n";
    return this->_num;
}

void Fixed :: setRawBits(int const raw)
{
    this->_num = raw;
}