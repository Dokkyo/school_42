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
    unsigned int        nb_philo;
    unsigned int        time_to_die;
    unsigned int        time_to_eat;
    unsigned int        time_to_sleep;
    unsigned int        nb_times_eat;
    pthread_mutex_t     *fork;
    pthread_mutex_t     print;
    int                 dead;
}               t_infos;

typedef struct  s_philo
{
    int             philo_n;
    long int        time_now;
    long int        time_start;
    t_infos         *infos;
    int             eat_counter;
    int             dead;
}               t_philo;

typedef struct  s_args
{
    unsigned int   *tab;
    t_philo         *philo;
}               t_args;

void            args_nbr_error(void);
void            args_syntax_error(int ac);
void            allocation_error(void);
unsigned int    ft_atoi(const char *nptr, int ac);
void            init_t_args(int ac, char **arg, t_args *args);
void            *start(void *arg);
void	        init_t_infos(t_infos *ithread, t_args *args, int ac);
long int        get_time(void);
long int        get_time_now(t_philo *info);



#endif
