/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:43:15 by naben-za          #+#    #+#             */
/*   Updated: 2021/02/18 13:42:18 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		signe;
	int		nbr;

	signe = 1;
	nbr = 0;
	while (*str <= 32)
		str++;
	while (*str == 43 || *str == 45)
	{
		if (*str == 45)
			signe *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nbr = (nbr * 10) + (*str - 48);
		str++;
	}
	return (nbr * signe);
}
