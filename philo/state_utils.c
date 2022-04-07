/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   state_utils.c                                      :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: naben-za <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/23 11:30:02 by naben-za		  #+#	#+#			 */
/*   Updated: 2022/03/30 18:53:32 by naben-za         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

void	ft_death(t_check *ph)
{
	int	i;

	i = -1;
	while (++i < (int)ph->infos->nb_philo)
		ph->ph[i].dead = 1;
}

void	odd_without_six_arg(t_philo *ph)
{
	anti_lock_order(ph);
	pthread_mutex_lock(&ph->infos->death);
	if (ph->dead != 1)
	{
		pthread_mutex_unlock(&ph->infos->death);
		pthread_mutex_lock(&ph->infos->print);
		printf("%ld %d has taken left fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		printf("%ld %d has taken right fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		pthread_mutex_unlock(&ph->infos->print);
	}
	else
		pthread_mutex_unlock(&ph->infos->death);
	ft_eat(ph);
	pthread_mutex_unlock(&ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
}

void	odd_with_six_arg(t_philo *ph)
{
	anti_lock_order(ph);
	pthread_mutex_lock(&ph->infos->death);
	if (ph->dead != 1 && ph->eat_counter != ph->infos->nb_times_eat)
	{
		pthread_mutex_unlock(&ph->infos->death);
		pthread_mutex_lock(&ph->infos->print);
		printf("%ld %d has taken left fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		printf("%ld %d has taken right fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		pthread_mutex_unlock(&ph->infos->print);
	}
	else
		pthread_mutex_unlock(&ph->infos->death);
	ft_eat(ph);
	pthread_mutex_unlock(&ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
}

void	pair_without_six_arg(t_philo *ph)
{
	anti_lock_order(ph);
	pthread_mutex_lock(&ph->infos->death);
	if (ph->dead != 1)
	{
		pthread_mutex_unlock(&ph->infos->death);
		pthread_mutex_lock(&ph->infos->print);
		printf("%ld %d has taken left fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		printf("%ld %d has taken right fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		pthread_mutex_unlock(&ph->infos->print);
	}
	else
		pthread_mutex_unlock(&ph->infos->death);
	ft_eat(ph);
	pthread_mutex_unlock(&ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
}

void	pair_with_six_arg(t_philo *ph)
{
	anti_lock_order(ph);
	pthread_mutex_lock(&ph->infos->death);
	if (ph->dead != 1 && ph->eat_counter != ph->infos->nb_times_eat)
	{
		pthread_mutex_unlock(&ph->infos->death);
		pthread_mutex_lock(&ph->infos->print);
		printf("%ld %d has taken left fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		printf("%ld %d has taken right fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		pthread_mutex_unlock(&ph->infos->print);
	}
	else
		pthread_mutex_unlock(&ph->infos->death);
	ft_eat(ph);
	pthread_mutex_unlock(&ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
}
