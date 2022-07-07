#include "Conv.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 0;
    else
    {
        Conv scal(av[1]);

        scal.detectType();
        scal.caster();
        scal.display();
    }
    return (0);
}