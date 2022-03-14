#include "philo.h"

void    ft_fork(t_philo *ph)
{
    if(ph->infos->nb_philo >= 2)
    {
        if (ph->philo_n % 2 != 0)
        {
            pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_lock(&ph->infos->fork[ph->philo_n]);
            gettimeofday(&ph->tv1, NULL);
            printf("%ld %d has taken a fork\n", ph->tv1.tv_usec, ph->philo_n);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n]);
        }
        if (ph->philo_n % 2 == 0)
        {
            pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 2]);
            gettimeofday(&ph->tv1, NULL);
            printf("%ld %d has taken a fork\n", ph->tv1.tv_usec, ph->philo_n);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 2]);
        }
    }
}

void    *start(void *arg)
{
    t_philo *p;
    p = arg;

    ft_fork(p);
}

int main(int ac, char **av)
{
    t_args      args;
    t_infos     infos_threads;
    pthread_t   *t;
    int         i;

    if (ac == 5 || ac == 6)
        init_t_args(ac, av, &args);
    else
        args_nbr_error();
    init_t_infos(&infos_threads, &args, ac);
    t = malloc(sizeof(pthread_t) * infos_threads.nb_philo);
    i = -1;
    while (++i < (int)infos_threads.nb_philo)
    {
        args.philo[i].infos = &infos_threads;
        args.philo[i].philo_n = i + 1;
        pthread_create(&t[i], NULL, &start, &args.philo[i]);
    }
    i = -1;
    while (++i < (int)infos_threads.nb_philo)
        pthread_join(t[i], NULL);
    return (0);
}