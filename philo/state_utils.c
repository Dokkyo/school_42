/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:30:02 by naben-za          #+#    #+#             */
/*   Updated: 2022/03/23 11:33:47 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	odd_without_six_arg(t_philo *ph)
{
	/*pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 1]);
	if (ph->infos->nb_philo % 2 != 0 && ph->philo_n == (int)ph->infos->nb_philo)
		pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 2]);
	else
		pthread_mutex_lock(&ph->infos->fork[ph->philo_n]);*/
	pthread_mutex_lock(&ph->l_fork);
	pthread_mutex_lock(ph->r_fork);
	pthread_mutex_lock(&ph->infos->print);
	if (ph->dead != 1)
	{
		printf("%ld %d has taken left fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		printf("%ld %d has taken right fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
	}
	pthread_mutex_unlock(&ph->infos->print);
	ft_eat(ph);
	/*pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 1]);
	if (ph->infos->nb_philo % 2 != 0 && ph->philo_n == (int)ph->infos->nb_philo)
		pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 2]);
	else
		pthread_mutex_unlock(&ph->infos->fork[ph->philo_n]);*/
	pthread_mutex_unlock(&ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
}

void	odd_with_six_arg(t_philo *ph)
{
	/*pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 1]);
	if (ph->infos->nb_philo % 2 != 0 && ph->philo_n == (int)ph->infos->nb_philo)
		pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 2]);
	else
		pthread_mutex_lock(&ph->infos->fork[ph->philo_n]);*/
	pthread_mutex_lock(&ph->l_fork);
	pthread_mutex_lock(ph->r_fork);
	pthread_mutex_lock(&ph->infos->print);
	if (ph->dead != 1 && ph->eat_counter != ph->infos->nb_times_eat)
	{
		printf("%ld %d has taken left fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		printf("%ld %d has taken right fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
	}
	pthread_mutex_unlock(&ph->infos->print);
	ft_eat(ph);
	/*pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 1]);
	if (ph->infos->nb_philo % 2 != 0 && ph->philo_n == (int)ph->infos->nb_philo)
		pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 2]);
	else
		pthread_mutex_unlock(&ph->infos->fork[ph->philo_n]);*/
	pthread_mutex_unlock(&ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
}

void	pair_without_six_arg(t_philo *ph)
{
	/*pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 1]);
	pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 2]);*/
	pthread_mutex_lock(&ph->l_fork);
	pthread_mutex_lock(ph->r_fork);
	pthread_mutex_lock(&ph->infos->print);
	if (ph->dead != 1)
	{
		printf("%ld %d has taken left fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		printf("%ld %d has taken right fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
	}
	pthread_mutex_unlock(&ph->infos->print);
	ft_eat(ph);
	/*pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 1]);
	pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 2]);*/
	pthread_mutex_unlock(&ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
}

void	pair_with_six_arg(t_philo *ph)
{
	/*pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 1]);
	pthread_mutex_lock(&ph->infos->fork[ph->philo_n - 2]);*/
	pthread_mutex_lock(&ph->l_fork);
	pthread_mutex_lock(ph->r_fork);
	pthread_mutex_lock(&ph->infos->print);
	if (ph->dead != 1
		&& ph->eat_counter != ph->infos->nb_times_eat)
	{
		printf("%ld %d has taken left fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
		printf("%ld %d has taken right fork\n",
			get_time() - ph->infos->time_start, ph->philo_n);
	}
	pthread_mutex_unlock(&ph->infos->print);
	ft_eat(ph);
	/*pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 1]);
	pthread_mutex_unlock(&ph->infos->fork[ph->philo_n - 2]);*/
	pthread_mutex_unlock(&ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
}
