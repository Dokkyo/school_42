#include "Zombie.hpp"

int main()
{
    Zombie  z2("Stack");
    Zombie  *z1;

    z2.announce();
    z1 = z2.newZombie("Heap");
    z1->announce();

    z2.randomChump("Stack aussi");

    delete z1;
    return (0);
}