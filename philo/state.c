/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: naben-za <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/23 11:27:07 by naben-za		  #+#	#+#			 */
/*   Updated: 2022/04/06 18:27:57 by naben-za         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->infos->death);
	if (ph->dead != 1)
	{
		pthread_mutex_unlock(&ph->infos->death);
		pthread_mutex_lock(&ph->infos->print);
		printf("%ld %d is thinking\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		pthread_mutex_unlock(&ph->infos->print);
	}
	else
		pthread_mutex_unlock(&ph->infos->death);
}

void	ft_sleep(t_philo *ph)
{
	pthread_mutex_lock(&ph->infos->death);
	if (ph->dead != 1)
	{
		pthread_mutex_unlock(&ph->infos->death);
		pthread_mutex_lock(&ph->infos->print);
		printf("%ld %d is sleeping\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		pthread_mutex_unlock(&ph->infos->print);
	}
	else
		pthread_mutex_unlock(&ph->infos->death);
	ft_usleep(ph->infos->time_to_sleep);
}

void	eat_with_sixargs(t_philo *ph)
{
	pthread_mutex_lock(&ph->infos->death);
	if (ph->dead != 1)
	{
		pthread_mutex_unlock(&ph->infos->death);
		if (ph->eat_counter != ph->infos->nb_times_eat)
		{
			pthread_mutex_lock(&ph->infos->print);
			printf("%ld %d is eating\n",
				get_time() - ph->infos->time_start, ph->philo_n);
			pthread_mutex_unlock(&ph->infos->print);
			++ph->eat_counter;
			if (ph->eat_counter == ph->infos->nb_times_eat)
			{
				pthread_mutex_lock(&ph->infos->eat);
				++ph->infos->end_eat;
				pthread_mutex_unlock(&ph->infos->eat);
			}
		}
	}
	else
		pthread_mutex_unlock(&ph->infos->death);
}

void	ft_eat(t_philo *ph)
{
	if (ph->infos->six_args == 0)
	{
		pthread_mutex_lock(&ph->infos->death);
		if (ph->dead != 1)
		{
			pthread_mutex_unlock(&ph->infos->death);
			pthread_mutex_lock(&ph->infos->print);
			printf("%ld %d is eating\n",
				get_time() - ph->infos->time_start, ph->philo_n);
			pthread_mutex_unlock(&ph->infos->print);
		}
		else
			pthread_mutex_unlock(&ph->infos->death);
	}
	else
		eat_with_sixargs(ph);
	pthread_mutex_lock(&ph->infos->eat);
	ph->last_time_eat = get_time();
	pthread_mutex_unlock(&ph->infos->eat);
	ft_usleep(ph->infos->time_to_eat);
}

void	ft_fork(t_philo *ph)
{
	if (ph->infos->nb_philo >= 2)
	{
		if (ph->philo_n % 2 != 0)
		{
			if (ph->infos->six_args == 0)
				odd_without_six_arg(ph);
			else
				odd_with_six_arg(ph);
		}
		if (ph->philo_n % 2 == 0)
		{
			if (ph->infos->six_args == 0)
				pair_without_six_arg(ph);
			else
				pair_with_six_arg(ph);
		}
	}
}
