/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: naben-za <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/23 11:15:47 by naben-za		  #+#	#+#			 */
/*   Updated: 2022/03/30 18:48:50 by naben-za         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	args;
	t_infos	infos_threads;
	t_check	ch;
	int		i;

	if (ac == 5 || ac == 6)
		init_t_args(ac, av, &args);
	else
		args_nbr_error();
	init_t_infos(&infos_threads, &args, ac);
	init_t_philo(&args, &infos_threads);
	ch.infos = &infos_threads;
	ch.ph = args.philo;
	launch_threads(&args, &infos_threads, &ch);
	i = -1;
	while (++i < args.tab[0])
		pthread_mutex_destroy(&args.philo[i].l_fork);
	pthread_mutex_destroy(&infos_threads.print);
	pthread_mutex_destroy(&infos_threads.eat);
	pthread_mutex_destroy(&infos_threads.death);
	free(args.philo);
	free(args.tab);
	return (0);
}
