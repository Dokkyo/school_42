#include "Fixed.hpp"

Fixed::Fixed() : _value(0), _bitFractPart(8)
{
    std::cout << "Default Constructor Called" << std::endl;
    (void)_bitFractPart;
    return;
}

Fixed::Fixed(int nbr) : _value(nbr) , _bitFractPart(8)
{
    std::cout << "Int Constructor Called" << std::endl;
    (void)_bitFractPart;
    //Convertir ici
    return;
}

Fixed::Fixed(float nbr) : _value(nbr) , _bitFractPart(8)
{
    std::cout << "Float Constructor Called" << std::endl;
    //Convertir ici
    return;
}

Fixed::~Fixed()
{
    std::cout << "Destructor Called" << std::endl;

    return;
}

Fixed::Fixed(Fixed const & src) : _bitFractPart(8)
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

std::ostream &      operator<<(std::ostream & o, Fixed const & rhs)
{
    o.setf ( std::ios::fixed, std::ios::floatfield );
    o << rhs.toFloat();

    return (o);
}

int         Fixed::getRawBits(void) const
{
    return (this->_value);
}

void        Fixed::setRawBits(int const raw)
{
    this->_value = raw;

    return;
}

float       Fixed::toFloat( void ) const
{
    //A finir
    return(this->_value);
}

int         Fixed::toInt( void ) const
{
    //A finir
    return(this->_value);
}
