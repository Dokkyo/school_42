#ifndef CONV_HPP
#define CONV_HPP

#include <cstdlib>
#include <string>
#include <iostream>

class Conv
{
    private:
    
        int             _i;
        double          _d;
        float           _f;
        char            _c;
        std::string     _str;
    
    public:

        Conv(std::string str);
        Conv(Conv & src);
        Conv &  operator=(Conv & rhs);
        ~Conv();

        int     isInt();
        int     isDouble();
        int     isChar();
        int     isFloat();

        void    detectType();
        void    caster();
        void    display() const;
};

#endif