#include "philo.h"

int    ft_check_death(t_check *ph)
{
    int i;

    i = -1;
    if (ph->infos->dead == 1)
    {
        while (++i < (int)ph->infos->nb_philo)
            ph->ph[i].dead = 1;
        return (1);
    }
    return (0);
}

int    ft_check_eat(t_check *ph)
{
    if (ph->infos->end_eat == (int)ph->infos->nb_philo)
        return (1);
    return (0);
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
        if (p->infos->dead == 1 || p->infos->end_eat == (int)p->infos->nb_philo)
            break ;
    }
    return (0);
}

void    *checker(void *arg)
{
    t_check *i;

    i = arg;
    while (1)  
        if (ft_check_death(i) == 1 || ft_check_eat(i) == 1)
            break ;
    return (0);
}

void    launch_threads(t_args *args, t_infos *info, t_check *ch)
{
    int i;
    pthread_t   *p;
    pthread_t   w;

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
