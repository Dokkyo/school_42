/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:02:21 by naben-za          #+#    #+#             */
/*   Updated: 2022/04/06 18:27:22 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_nbr_error(void)
{
	printf("Invalid number of arguments.\n");
	exit(1);
}

void	args_syntax_error(int ac)
{
	printf("arg syntax number %d is incorrect.\n", ac);
	exit(2);
}

void	allocation_error(void)
{
	printf("Allocation failed.\n");
	exit(3);
}

void	negativ_args(int *tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (tab[i] < 0)
		{
			printf("Negativ arg.\n");
			exit(4);
		}
		++i;
	}
}

void	anti_lock_order(t_philo *ph)
{
	if (ph->philo_n == (int)ph->infos->nb_philo)
	{
		pthread_mutex_lock(ph->r_fork);
		pthread_mutex_lock(&ph->l_fork);
	}
	else
	{
		pthread_mutex_lock(&ph->l_fork);
		pthread_mutex_lock(ph->r_fork);
	}
}
