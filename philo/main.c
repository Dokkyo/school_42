#include "philo.h"

void    *start(void *arg)
{
    t_philo *t;
    int     i;

    t = arg;
    i = 0;
    pthread_mutex_lock(&t->mutex);
    usleep(2000000);
    pthread_mutex_unlock(&t->mutex);
}

int main(int ac, char **av)
{
    t_args      args;
    t_philo     philo;
    int         i;

    if (ac == 5 || ac == 6)
        init_t_args(ac, av, &args);
    else
        args_nbr_error();
    pthread_mutex_init(&philo.mutex, NULL);
    philo.th = malloc(sizeof(philo.th) * args.nb_philo);
    i = -1;
    while (++i < args.nb_philo)
    {
        philo.philo_n = i + 1;
        pthread_create(philo.th + i, NULL, &start, &philo);
        printf("thread %d executing\n", philo.philo_n);
    }
    i = -1;
    while (++i < args.nb_philo)
    {
        pthread_join(philo.th[i], NULL);
        printf("thread %d has finished execution\n", i + 1);
    }
    pthread_mutex_destroy(&philo.mutex);
    return (0);
}