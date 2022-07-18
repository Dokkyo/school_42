#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>

class Span
{
    private:

        unsigned int        _size;
        std::vector<int>    _a;
        int                 _res;

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
        class SizeException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Size problem.");
                }
        };
        void    addNumber(int nbr);
        int     Abs(int nb);
        int     shortestSpan();
        int     longestSpan();
        void    iterator(unsigned int N);
};

#endif