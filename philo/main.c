#include "philo.h"

void    *start(void *arg)
{
    t_philo *p;
    p = arg;

        gettimeofday(&p->tv1, NULL);
        printf("%d %d has taken a fork\n", p->tv1.tv_usec, p->philo_n);
        gettimeofday(&p->tv1, NULL);
        printf("%d %d is eating\n", p->tv1.tv_usec, p->philo_n);
        usleep(p->infos.time_to_eat);
        gettimeofday(&p->tv1, NULL);
        printf("%d %d is sleeping\n", p->tv1.tv_usec, p->philo_n);
        usleep(p->infos.time_to_sleep);
        gettimeofday(&p->tv1, NULL);
        printf("%d %d is thinking\n", p->tv1.tv_usec, p->philo_n);
        gettimeofday(&p->tv1, NULL);
        //if ((unsigned int)p->tv1.tv_usec - (unsigned int)p->infos.tv.tv_usec >= p->infos.time_to_die)
          //  break;
    //printf("test\n");
    //usleep(2000000);
    return (0);
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
        args.philo[i].philo_n = i + 1;
        pthread_create(&t[i], NULL, &start, &args.philo[i]);
    }
    i = -1;
    while (++i < (int)infos_threads.nb_philo)
        pthread_join(t[i], NULL);
    return (0);
}