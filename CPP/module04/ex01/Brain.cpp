#include "classes.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain & src)
{
    //copie profonde ?
    *this = src;
}

Brain& Brain::operator=(Brain & rhs)
{
    int i = -1;

    while (++i < 100)
        this->ideas[i] = rhs.ideas[i];

    return(*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}