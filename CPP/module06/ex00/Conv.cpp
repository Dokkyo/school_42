#include "Conv.hpp"

Conv::Conv(std::string str) : _str(str)
{
    std::cout << _d << std::endl;
    std::cout << static_cast<char>(_d) << std::endl;
    
    std::cout << "Conv Constructor Called" << std::endl;
}

Conv::Conv(Conv & src)
{
    *this = src;
}

Conv & Conv::operator=(Conv & rhs)
{
    this->_i = rhs._i;
    this->_d = rhs._d;
    this->_f = rhs._f;
    this->_c = rhs._c;

    return (*this);
}

Conv::~Conv()
{
    std::cout << "Conv Destructor Called" << std::endl;
}

int     Conv::isInt()
{
    
}

void    Conv::detectType()
{

}

void    Conv::caster()
{
    this->_i = static_cast<int>(this->_d);
    this->_f = static_cast<float>(this->_d);
    this->_c = static_cast<char>(this->_d);
}

void    Conv::display() const
{
    std::cout << "char: " << this->_c << std::endl;
    std::cout << "int: " << this->_i << std::endl;
    std::cout << "float: " << this->_f << std::endl;
    std::cout << "double: " << this->_d << std::endl;
}
