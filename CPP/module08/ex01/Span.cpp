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

