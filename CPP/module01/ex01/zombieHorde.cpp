#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name)
{
    Zombie  *zombie = new Zombie[N];
    int     i = 0;

    while (i < N)
        zombie[i++]._name = name;
    return(zombie);
}
