/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: naben-za <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/23 11:36:24 by naben-za		  #+#	#+#			 */
/*   Updated: 2022/03/23 11:36:48 by naben-za         ###   ########.fr       */
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
	long int	t_now;

	t_now = get_time();
	return (t_now - ph->last_time_eat);
}
