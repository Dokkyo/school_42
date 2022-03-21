#include "philo.h"

int    ft_check_death(t_check *ph)
{
    int i;

    i = -1;
    if (ph->infos->dead == 1)
    {
        while (++i < ph->infos->nb_philo)
            ph->ph[i].dead = 1;
        return (1);
    }
    return (0);
}

int     ft_check_eat(t_check *ph)
{
    int i;

    i = -1;
    while (++i < ph->infos->nb_philo)
    {
        if (ph->ph[i].eat_counter != ph->infos->nb_times_eat)
            return (0);
    }
    return (1);
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
        if (p->infos->dead == 1)
            break ;
    }
}

void    *checker(void *arg)
{
    t_check *i;

    i = arg;
    while (1)  
        if (ft_check_death(i) == 1)
            break ;
}

void    launch_threads(t_args *args, t_infos *info, t_check *ch)
{
    int i;
    pthread_t   *p;
    pthread_t   w;
    (void)ch;
    p = malloc(sizeof(pthread_t) * info->nb_philo);
    pthread_create(&w, NULL, &checker, ch);
    info->time_start = get_time();
    i = -1;
    while (++i < (int)info->nb_philo)
        pthread_create(&p[i], NULL, &philo, &args->philo[i]);
    i = -1;
    while (++i < (int)info->nb_philo)
        pthread_join(p[i], NULL);
    pthread_join(w, NULL);
    free(p);
}

int main(int ac, char **av)
{
    t_args      args;
    t_infos     infos_threads;
    t_check     ch;


    if (ac == 5 || ac == 6)
        init_t_args(ac, av, &args);
    else
        args_nbr_error();
    init_t_infos(&infos_threads, &args, ac);
    init_t_philo(&args, &infos_threads);
    ch.infos = &infos_threads;
    ch.ph = args.philo;
    launch_threads(&args, &infos_threads, &ch);
    free(args.philo);
    free(args.tab);
    free(infos_threads.fork);
    return (0);
}
