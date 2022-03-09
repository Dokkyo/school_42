#include "philo.h"

void    args_nbr_error(void)
{
    printf("Invalid number of arguments.\n");
    exit(1);
}

void    args_syntax_error(int ac)
{
    printf("arg syntax number %d is incorrect.\n", ac);
    exit(2);
}