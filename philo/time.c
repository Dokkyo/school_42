/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: naben-za <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/23 11:36:24 by naben-za		  #+#	#+#			 */
/*   Updated: 2022/03/30 18:46:21 by naben-za         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((1000 * time.tv_sec) + (time.tv_usec / 1000));
}

long int	get_time_now(t_philo *ph)
{
	return ((get_time() - ph->infos->time_start)
		- (ph->last_time_eat - ph->infos->time_start));
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
