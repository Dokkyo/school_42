#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct  s_infos
{
    unsigned long   nb_philo;
    unsigned long   time_to_die;
    unsigned long   time_to_eat;
    unsigned long   time_to_sleep;
    unsigned long   nb_times_eat;
    struct timeval  tv;
}               t_infos;

typedef struct  s_philo
{
    int             philo_n;
    struct timeval  tv1;
    t_infos         infos;
}               t_philo;

typedef struct  s_args
{
    unsigned long   *tab;
    t_philo         *philo;
}               t_args;

void            args_nbr_error(void);
void            args_syntax_error(int ac);
void            allocation_error(void);
unsigned long   ft_atoi(const char *nptr, int ac);
void            init_t_args(int ac, char **arg, t_args *args);
void            *start(void *arg);
void	        init_t_infos(t_infos *ithread, t_args *args, int ac);


#endif
