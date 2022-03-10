#include "philo.h"

void    *start(void *arg)
{
    t_args *t;
    static int     i;

    t = arg;
    pthread_mutex_lock(&t->mutex);
    //while (++i < t->nb_philo)
    //{
        usleep(2000000);
        printf("philo %d attend\n", t->philo[i].philo_n);
        ++i;
    //}
    pthread_mutex_unlock(&t->mutex);
}

int main(int ac, char **av)
{
    t_args      args;
    int         i;

    if (ac == 5 || ac == 6)
        init_t_args(ac, av, &args);
    else
        args_nbr_error();
    pthread_mutex_init(&args.mutex, NULL);
    args.philo = malloc(sizeof(args.philo) * args.nb_philo);
    i = -1;
    while (++i < args.nb_philo)
    {
        args.philo[i].philo_n = i + 1;
        pthread_create(&args.philo[i].th, NULL, &start, &args);
        pthread_mutex_init(&args.philo[i].mutex1, NULL);
        printf("thread %d executing\n", i + 1);
    }
    i = -1;
    while (++i < args.nb_philo)
    {
        pthread_join(args.philo[i].th, NULL);
        pthread_mutex_destroy(&args.philo[i].mutex1);
        printf("thread %d has finished execution\n", i + 1);
    }
    pthread_mutex_destroy(&args.mutex);
    return (0);
}
