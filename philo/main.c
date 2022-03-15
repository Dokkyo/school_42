#include "philo.h"

void    ft_die(t_philo *ph)
{
    if (get_time_now(ph->infos) >= (long int)ph->infos->time_to_die)
    {
        ph->dead = 1;
        pthread_mutex_lock(&ph->infos->print);
        printf("%ld %d died\n", get_time(), ph->philo_n);
        pthread_mutex_unlock(&ph->infos->print);
    }
}

void    ft_think(t_philo *ph)
{
    pthread_mutex_lock(&ph->infos->print);
    printf("%ld %d is thinking\n", get_time(), ph->philo_n);
    pthread_mutex_unlock(&ph->infos->print);
}

void    ft_sleep(t_philo *ph)
{
    pthread_mutex_lock(&ph->infos->print);
    printf("%ld %d is sleeping\n", get_time(), ph->philo_n);
    pthread_mutex_unlock(&ph->infos->print);
    usleep(ph->infos->time_to_sleep * 1000);
}

void    ft_eat(t_philo *ph)
{
    pthread_mutex_lock(&ph->infos->print);
    printf("%ld %d is eating\n", get_time(), ph->philo_n);
    if (ph->infos->nb_times_eat)
        ++ph->eat_counter;
    pthread_mutex_unlock(&ph->infos->print);
    usleep(ph->infos->time_to_eat * 1000);
}

void    ft_fork(t_philo *ph)
{
    if(ph->infos->nb_philo >= 2)
    {
        if (ph->philo_n % 2 != 0)
        {
            pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_lock(&ph->infos->fork[ph->philo_n]);
            pthread_mutex_lock(&ph->infos->print);
            printf("%ld %d has taken a fork\n", get_time(), ph->philo_n);
            pthread_mutex_unlock(&ph->infos->print);
            ft_eat(ph);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n]);
        }
        if (ph->philo_n % 2 == 0)
        {
            pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 2]);
            pthread_mutex_lock(&ph->infos->print);
            printf("%ld %d has taken a fork\n", get_time(), ph->philo_n);
            pthread_mutex_unlock(&ph->infos->print);
            ft_eat(ph);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 2]);
        }
    }
}

void    *start(void *arg)
{
    t_philo *p;
    p = arg;

    while (1)
    {
        p->infos->time_start = get_time();
        printf("t_start %ld\n", p->infos->time_start);
        ft_fork(p);
        ft_sleep(p);
        ft_think(p);
        ft_die(p);
    }
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
        args.philo[i].eat_counter = 0;
        args.philo[i].philo_n = i + 1;
        args.philo[i].dead = 0;
        pthread_create(&t[i], NULL, &start, &args.philo[i]);
    }
    i = -1;
    while (++i < (int)infos_threads.nb_philo)
        pthread_join(t[i], NULL);
    return (0);
}
