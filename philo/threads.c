/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: naben-za <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/23 11:34:26 by naben-za		  #+#	#+#			 */
/*   Updated: 2022/03/30 18:55:31 by naben-za         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_check *ph)
{
	int	i;

	i = (int)ph->infos->nb_philo;
	while (--i >= 0)
	{
		pthread_mutex_lock(&ph->infos->eat);
		if (get_time_now(&ph->ph[i]) >= (long int)ph->infos->time_to_die)
		{
			pthread_mutex_unlock(&ph->infos->eat);
			pthread_mutex_lock(&ph->infos->print);
			printf("%ld %d died\n",
				get_time() - ph->infos->time_start, ph->ph[i].philo_n);
			pthread_mutex_unlock(&ph->infos->print);
			pthread_mutex_lock(&ph->infos->death);
			ph->infos->dead = 1;
			ft_death(ph);
			pthread_mutex_unlock(&ph->infos->death);
			return (1);
		}
		else
			pthread_mutex_unlock(&ph->infos->eat);
	}
	return (0);
}

int	ft_check(t_check *ph)
{
	ft_usleep(ph->infos->time_to_die);
	pthread_mutex_lock(&ph->infos->eat);
	if (ph->infos->end_eat == (int)ph->infos->nb_philo)
	{
		pthread_mutex_unlock(&ph->infos->eat);
		return (1);
	}
	else
		pthread_mutex_unlock(&ph->infos->eat);
	if (ft_check_death(ph))
		return (1);
	return (0);
}

void	*philo(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		ft_fork(p);
		ft_sleep(p);
		ft_think(p);
		pthread_mutex_lock(&p->infos->death);
		pthread_mutex_lock(&p->infos->eat);
		if (p->infos->dead == 1 || p->infos->end_eat == (int)p->infos->nb_philo)
		{
			pthread_mutex_unlock(&p->infos->death);
			pthread_mutex_unlock(&p->infos->eat);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&p->infos->death);
			pthread_mutex_unlock(&p->infos->eat);
		}
	}
	return (0);
}

void	*checker(void *arg)
{
	t_check	*i;

	i = arg;
	while (1)
	{
		if (ft_check(i) == 1)
			break ;
	}
	return (0);
}

void	launch_threads(t_args *args, t_infos *info, t_check *ch)
{
	int			i;
	pthread_t	*p;
	pthread_t	w;

	p = malloc(sizeof(pthread_t) * info->nb_philo);
	info->time_start = get_time();
	pthread_create(&w, NULL, &checker, ch);
	i = -1;
	while (++i < (int)info->nb_philo)
		pthread_create(&p[i], NULL, &philo, &args->philo[i]);
	i = -1;
	pthread_join(w, NULL);
	while (++i < (int)info->nb_philo)
		pthread_join(p[i], NULL);
	free(p);
}
