#include "philo.h"

void    ft_check(t_infos *ph)
{
    if (ph->dead == 1)
    {
        printf("OK\n");
        exit(0);
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
        ft_die(p);
    }
}

void    *checker(void *arg)
{
    t_infos *i;

    i = arg;
    while (1)
        ft_check(arg);
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
    pthread_create(&w, NULL, &checker, &infos_threads);
    infos_threads.time_start = get_time();
    i = -1;
    while (++i < (int)infos_threads.nb_philo)
    {
        args.philo[i].infos = &infos_threads;
        args.philo[i].eat_counter = 0;
        args.philo[i].philo_n = i + 1;
        args.philo[i].dead = 0;
        pthread_create(&p[i], NULL, &philo, &args.philo[i]);
    }
    i = -1;
    while (++i < (int)infos_threads.nb_philo)
        pthread_join(p[i], NULL);
    pthread_join(w, NULL);
    return (0);
}
