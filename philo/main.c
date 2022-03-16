#include "philo.h"

void    ft_die(t_philo *ph)
{
    //printf("time start %ld philo %d\n", ph->time_start, ph->philo_n);
    //printf("time now %ld philo %d\n", get_time_now(ph), ph->philo_n);
    if (get_time_now(ph) >= (long int)ph->infos->time_to_die)
    {
        ph->infos->dead = 1;
        pthread_mutex_lock(&ph->infos->print);
        printf("%ld %d died\n", get_time(), ph->philo_n);
        pthread_mutex_unlock(&ph->infos->print);
    }
    else
        ph->time_start = get_time();
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
    if (ph->infos->nb_times_eat && ph->eat_counter != ph->infos->nb_times_eat)
        ++ph->eat_counter;
    pthread_mutex_unlock(&ph->infos->print);
    usleep(ph->infos->time_to_eat * 1000);
    //ph->time_start = get_time();
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
            printf("%ld %d has taken left fork\n", get_time(), ph->philo_n);
            printf("%ld %d has taken right fork\n", get_time(), ph->philo_n);
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
            printf("%ld %d has taken left fork\n", get_time(), ph->philo_n);
            printf("%ld %d has taken right fork\n", get_time(), ph->philo_n);
            pthread_mutex_unlock(&ph->infos->print);
            ft_eat(ph);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 2]);
        }
    }
}

void    *philo(void *arg)
{
    t_philo *p;
    p = arg;

    while (1)
    {
        ft_fork(p);
        ft_sleep(p);
        ft_think(p);
    }
}

void    *watcher(void *arg)
{
    t_infos *i;

    i = arg;
    ft_die(arg);
}

int main(int ac, char **av)
{
    t_args      args;
    t_infos     infos_threads;
    pthread_t   *p;
    pthread_t   w;
    int         i;

    if (ac == 5 || ac == 6)
        init_t_args(ac, av, &args);
    else
        args_nbr_error();
    init_t_infos(&infos_threads, &args, ac);
    p = malloc(sizeof(pthread_t) * infos_threads.nb_philo);
    pthread_create(&w, NULL, &watcher, &infos_threads);
    i = -1;
    while (++i < (int)infos_threads.nb_philo)
    {
        args.philo[i].infos = &infos_threads;
        args.philo[i].eat_counter = 0;
        args.philo[i].philo_n = i + 1;
        args.philo[i].dead = 0;
        args.philo[i].time_start = get_time();
        pthread_create(&p[i], NULL, &philo, &args.philo[i]);
    }
    i = -1;
    pthread_join(w, NULL);
    while (++i < (int)infos_threads.nb_philo)
        pthread_join(p[i], NULL);
    return (0);
}
