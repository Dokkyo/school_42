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
	int i;

    args->nb_philo = ft_atoi(arg[1], 1);
    args->time_to_die = ft_atoi(arg[2], 2);
    args->time_to_eat = ft_atoi(arg[3], 3);
    args->time_to_sleep = ft_atoi(arg[4], 4);
    if (ac == 6)
        args->nb_times_eat = ft_atoi(arg[5], 5);
	/*pthread_mutex_init(&args->mutex, NULL);
	pthread_mutex_init(&args->philo->mutex1, NULL);
	args->philo = malloc(sizeof(args->philo) * args->nb_philo);
    i = -1;
    while (++i < args->nb_philo)
    {
        pthread_create(&args->philo[i].th, NULL, &start, &args);
        printf("thread %d executing\n", i + 1);
    }
    i = -1;
    while (++i < args->nb_philo)
    {
        pthread_join(args->philo[i].th, NULL);
        printf("thread %d has finished execution\n", i + 1);
    }
	//pthread_mutex_destroy(&args->philo->mutex1);
	pthread_mutex_destroy(&args->mutex);*/
}
