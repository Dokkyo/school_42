#include "Conv.hpp"



int main(int ac, char **av)
{
    if (ac != 2)
        return 0;
    else
    {
        Conv conv(av[1]);

        conv.detectType();
        conv.display();
    }

    return (0);
}