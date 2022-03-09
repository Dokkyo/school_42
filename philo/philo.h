#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct  s_args
{
    unsigned long   nb_philo;
    unsigned long   time_to_die;
    unsigned long   time_to_eat;
    unsigned long   time_to_sleep;
    unsigned long   nb_times_eat;
}               t_args;

typedef struct  s_philo
{
    pthread_t       *th;
    pthread_mutex_t mutex;
    struct timeval  tv;
    int             philo_n;
}               t_philo;

void            args_nbr_error(void);
void            args_syntax_error(int ac);
unsigned long   ft_atoi(const char *nptr, int ac);
void            init_t_args(int ac, char **arg, t_args *philo);

#endif