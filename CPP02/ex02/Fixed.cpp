#include "Fixed.h"

Fixed :: Fixed()
{
    // std::cout << "Default constructor called\n";

    this->_num = 0;
}

Fixed :: Fixed(Fixed const &copy)
{
    // std::cout << "Copy constructor called\n";

    this->_num = copy.getRawBits();
}

Fixed :: Fixed(const int num) : _num(num << _bits)
{
    // std::cout << "Int constructor called\n";
}

Fixed :: Fixed(const float num) : _num(std::roundf(num * (1 << _bits)))
{
    // std::cout << "Float constructor called\n";
}

Fixed :: ~Fixed()
{
    // std::cout << "Destructor called\n";
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
    // std::cout << "Copy assignment operator called\n";

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

//      Comparison operators

bool Fixed :: operator>(Fixed const &rhs) const
{
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed :: operator<(Fixed const &rhs) const
{
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed :: operator>=(Fixed const &rhs) const
{
    return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed :: operator<=(Fixed const &rhs) const
{
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed :: operator==(Fixed const &rhs) const
{
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed :: operator!=(Fixed const &rhs) const
{
    return this->getRawBits() != rhs.getRawBits();
}

//      Arithmetic operators

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

//      Increment/decrement

Fixed & Fixed :: operator++( void ) // prefix
{
    ++this->_num;

    return (*this);
}

Fixed Fixed :: operator++( int ) // postfix: returns old num with tmp and this num is increased
{
    Fixed tmp(*this);

    tmp._num = this->_num++;
    
    return tmp;
}

Fixed & Fixed :: operator--( void ) // prefix
{
    --this->_num;

    return (*this);
}

Fixed Fixed :: operator--( int ) // postfix
{
    Fixed tmp(*this);

    tmp._num = this->_num--;
    
    return tmp;
}


// MIN AND MAX
Fixed & Fixed :: min(Fixed &one, Fixed &two) 
{
    if (one.getRawBits() > two.getRawBits())
        return two;
    return one;
}

const Fixed & Fixed :: min(Fixed const &one, Fixed const &two) 
{
    if (one.getRawBits() > two.getRawBits())
        return two;
    return one;
}

Fixed & Fixed :: max(Fixed &one, Fixed &two) 
{
    if (one.getRawBits() < two.getRawBits())
        return two;
    return one;
}

const Fixed & Fixed :: max(Fixed const &one, Fixed const &two) 
{
    if (one.getRawBits() < two.getRawBits())
        return two;
    return one;
}