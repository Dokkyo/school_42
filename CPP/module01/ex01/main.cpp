#include "Zombie.hpp"

int main()
{
    Zombie  z2("Mother Zombie");
    Zombie  *z1;

    z1 = z2.zombieHorde(10, "Child zombie");
    int i = 0;
    while (i++ < 10)
        z1->announce();

    delete [] z1;
    return (0);
}
