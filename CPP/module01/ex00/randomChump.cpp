#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
    Zombie  zombie(name);

    std::cout << zombie._name << ": BraiiiiinnnnzzzzzZ.." << std::endl;
}

