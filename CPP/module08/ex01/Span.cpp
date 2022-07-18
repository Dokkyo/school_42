#include "Span.hpp"

Span::Span() : _size(0)
{
    std::cout << "Default Constructor Called" << std::endl;
}

Span::Span(unsigned int N) : _size(N)
{
    std::cout << "Default Constructor Called with size " << N << std::endl;
}

Span::~Span()
{
    std::cout << "Default Destructor Called" << std::endl;
}

void    Span::addNumber(int nbr)
{
    if (this->_a.size() < this->_size)
        this->_a.push_back(nbr);
    else
        throw Span::MaxReachedException();
}

int     Span::Abs(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}

int     Span::shortestSpan()
{
    if (this->_a.size() > 1)
    {
        for(int i = 0; i < this->_size; ++i)
        {
            for(int j = 1; j < this->_size; ++j)
            {
                // this->_res = i;
                //  if (*(it + 1) - *it < this->_res)
                //      this->_res = this->Abs(*(it + 1) - *it);
            }
        }
        return (this->_res);
    }
    else
        throw Span::SizeException();
}

int     Span::longestSpan()
{
    if (this->_a.size() > 1)
    {
        for(std::vector<int>::iterator it = this->_a.begin(); it+1 != this->_a.end(); ++it)
        {
            if (*(it + 1) - *it > this->_res)
                this->_res = this->Abs(*(it + 1) - *it);
        }
        return (this->_res);
    }
    else
        throw Span::SizeException();
}

void    Span::iterator(unsigned int N)
{
    if (N > this->_size)
        throw Span::SizeException();
    else
    {
        for(unsigned int i = 0; i < N; ++i)
        {
            srand (time(NULL));
            
            this->addNumber(rand());
        }
    }
}