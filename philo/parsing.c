/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: naben-za <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/23 11:17:18 by naben-za		  #+#	#+#			 */
/*   Updated: 2022/04/05 10:42:33 by naben-za         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

void	init_t_args(int ac, char **arg, t_args *args)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	args->tab = malloc(sizeof(int) * (ac - 1));
	if (!args->tab)
		allocation_error();
	while (j < ac)
	{
		args->tab[i] = ft_atoi(arg[j], j);
		++i;
		++j;
	}
	negativ_args(args->tab, ac);
	args->philo = malloc(sizeof(t_philo) * args->tab[0]);
	if (!args->philo)
		allocation_error();
}

void	init_mutex(t_infos *ithreads)
{
	pthread_mutex_init(&ithreads->print, NULL);
	pthread_mutex_init(&ithreads->death, NULL);
	pthread_mutex_init(&ithreads->eat, NULL);
}

void	init_t_infos(t_infos *ithread, t_args *args, int ac)
{
	ithread->nb_philo = args->tab[0];
	ithread->time_to_die = args->tab[1];
	ithread->time_to_eat = args->tab[2];
	ithread->time_to_sleep = args->tab[3];
	ithread->six_args = 0;
	ithread->nb_times_eat = 0;
	ithread->end_eat = 0;
	ithread->dead = 0;
	if (ac == 6)
	{
		ithread->nb_times_eat = args->tab[4];
		ithread->six_args = 1;
	}
	init_mutex(ithread);
}

void	init_t_philo(t_args *args, t_infos *info)
{
	int	i;

	i = -1;
	while (++i < (int)args->tab[0])
	{
		args->philo[i].infos = info;
		args->philo[i].last_time_eat = 0;
		args->philo[i].eat_counter = 0;
		args->philo[i].philo_n = i + 1;
		args->philo[i].dead = 0;
		args->philo[i].r_fork = NULL;
		pthread_mutex_init(&args->philo[i].l_fork, NULL);
	}
	i = -1;
	while (++i < (int)args->tab[0])
	{
		if (i == (int)info->nb_philo - 1)
			args->philo[i].r_fork = &args->philo[0].l_fork;
		else
			args->philo[i].r_fork = &args->philo[i + 1].l_fork;
	}
}
