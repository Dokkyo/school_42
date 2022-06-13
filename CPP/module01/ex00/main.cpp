#include "Zombie.hpp"

void    Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiinnnnzzzzzZ.." << std::endl;
}

Zombie* Zombie::newZombie( std::string name )
{
    Zombie  zombie;

    zombie._name = name;
    return (&zombie);
}

void Zombie::randomChump( std::string name )
{
    Zombie  zombie;

    zombie._name = name;
    std::cout << zombie._name << ": BraiiiiinnnnzzzzzZ.." << std::endl;
}