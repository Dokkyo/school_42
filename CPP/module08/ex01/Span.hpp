#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

class Span
{
    private:

        unsigned int        _size;
        std::vector<int>    _a;

    public:

        Span();
        Span(unsigned int N);
        ~Span();

        class MaxReachedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Maximum Numbers was added.");
                }
        };
        void    addNumber(int nbr);
};

#endif