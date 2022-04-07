/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: naben-za <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/23 11:19:20 by naben-za		  #+#	#+#			 */
/*   Updated: 2022/03/30 19:05:01 by naben-za         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr, int ac)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			res = res * 10 + (nptr[i++] - 48);
		else
			args_syntax_error(ac);
	}
	res *= sign;
	return (res);
}
