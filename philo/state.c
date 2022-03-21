#include "philo.h"

void    ft_die(t_philo *ph)
{
    if (get_time_now(ph) >= (long int)ph->infos->time_to_die)
    {
        pthread_mutex_lock(&ph->infos->print);
        if (ph->dead != 1)
            printf("%ld %d died\n", get_time() - ph->infos->time_start, ph->philo_n);
        ph->infos->dead = 1;
        pthread_mutex_unlock(&ph->infos->print);
    }
}

void    ft_think(t_philo *ph)
{
    pthread_mutex_lock(&ph->infos->print);
    if (ph->dead != 1)
        printf("%ld %d is thinking\n", get_time() - ph->infos->time_start, ph->philo_n);
    pthread_mutex_unlock(&ph->infos->print);
}

void    ft_sleep(t_philo *ph)
{
    pthread_mutex_lock(&ph->infos->print);
    if (ph->dead != 1)
        printf("%ld %d is sleeping\n", get_time() - ph->infos->time_start, ph->philo_n);
    pthread_mutex_unlock(&ph->infos->print);
    usleep(ph->infos->time_to_sleep * 1000);
}

void    ft_eat(t_philo *ph)
{
    pthread_mutex_lock(&ph->infos->print);
    if (ph->dead != 1)
        printf("%ld %d is eating\n", get_time() - ph->infos->time_start, ph->philo_n);
    if (ph->infos->six_args == 1)
    {
        if (ph->eat_counter != ph->infos->nb_times_eat)
            ++ph->eat_counter;
    }
    pthread_mutex_unlock(&ph->infos->print);
    usleep(ph->infos->time_to_eat * 1000);
    ph->last_time_eat = get_time();
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
            if (ph->dead != 1)
            {   
                printf("%ld %d has taken left fork\n", get_time() - ph->infos->time_start, ph->philo_n);
                printf("%ld %d has taken right fork\n", get_time() - ph->infos->time_start, ph->philo_n);
            }
            pthread_mutex_unlock(&ph->infos->print);
            ft_eat(ph);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n]);
        }
        usleep(500);
        if (ph->philo_n % 2 == 0)
        {
            pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 2]);
            pthread_mutex_lock(&ph->infos->print);
            if (ph->dead != 1)
            {
                printf("%ld %d has taken left fork\n", get_time() - ph->infos->time_start, ph->philo_n);
                printf("%ld %d has taken right fork\n", get_time() - ph->infos->time_start, ph->philo_n);
            }
            pthread_mutex_unlock(&ph->infos->print);
            ft_eat(ph);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 1]);
            pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 2]);
        }
    }
}
