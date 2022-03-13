#include "philo.h"

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

unsigned long   ft_atoi(const char *nptr, int ac)
{
	unsigned long   i;
	unsigned long   res;
	int		        sign;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			res = res * 10 + (nptr[i++] - 48);
		else
			args_syntax_error(ac);
	}
	res *= sign;
	return (res);
}

void    init_t_args(int ac, char **arg, t_args *args)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	args->tab = malloc(sizeof(unsigned long) * (ac - 1));
	if (!args->tab)
		allocation_error();
	while (j < ac)
	{
		args->tab[i] = ft_atoi(arg[j], j);
		++i;
		++j;
	}
	args->philo = malloc(sizeof(t_philo) * args->tab[0]);
	if (!args->philo)
		allocation_error();
}

void	init_t_infos(t_infos *ithread, t_args *args, int ac)
{
	ithread->nb_philo = args->tab[0];
	ithread->time_to_die = args->tab[1];
	ithread->time_to_eat = args->tab[2];
	ithread->time_to_sleep = args->tab[3];
	if (ac == 6)
		ithread->nb_philo = args->tab[4];
	gettimeofday(&ithread->tv, NULL);
}