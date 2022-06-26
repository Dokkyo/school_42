#include "classes.hpp"

Dog::Dog() : _type("Dog")
{
    this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog & src) : Animal()
{
    //copie profonde ?
    *this = src;
}

Dog& Dog::operator=(Dog & rhs)
{
    this->_type = rhs._type;

    return(*this);
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "WAF" << std::endl;
}

std::string     Dog::getType() const
{
    return (this->_type);
}