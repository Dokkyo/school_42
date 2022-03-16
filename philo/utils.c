#include "philo.h"

long int    get_time(void)
{
    struct timeval   time;

    gettimeofday(&time, NULL);
    return ((1000 * time.tv_sec) + (time.tv_usec / 1000));
}

long int    get_time_now(t_philo *info)
{
    long int    t_now;

    t_now = get_time();
    return (t_now - info->time_start);
}
