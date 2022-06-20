#include "Fixed.hpp"

Fixed::Fixed() : _value(0), _bit(8)
{
    std::cout << "Default Constructor Called" << std::endl;

    return;
}

Fixed::~Fixed()
{
    std::cout << "Destructor Called" << std::endl;

    return;
}

Fixed::Fixed(Fixed const & src) : _bit(8)
{
    std::cout << "Copy Constructor Called" << std::endl;
    
    *this = src;
    return;
}

Fixed &     Fixed::operator=(Fixed const & rhs) 
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &rhs)
        this->_value = rhs.getRawBits();

    return (*this);
}

int         Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function Called" << std::endl;

    return (this->_value);
}

void        Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}
