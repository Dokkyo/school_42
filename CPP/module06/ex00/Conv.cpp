#include "Conv.hpp"

Conv::Conv(std::string str) : _str(str)
{
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

// int     Conv::isChar()
// {

// }

// int     Conv::isInt()
// {

// }

// int     Conv::isDouble()
// {

// }

// int     Conv::isFloat()
// {

// }

// void    Conv::setC(int i)
// {
//     this->_c = i;
// }

// void    Conv::detectType()
// {

// }

// void    Conv::caster()
// {

// }

// void    Conv::display()
// {
//     std::cout << "char: ";
//     std::cout << "int: " << this->_i << std::endl;
//     std::cout << "float: " << this->_f << std::endl;
//     std::cout << "double: " << this->_d << std::endl;
// }