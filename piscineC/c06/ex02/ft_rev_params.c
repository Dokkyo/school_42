/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 09:19:50 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/23 09:24:22 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	int i;

	i = ac;
	while (i > 1)
	{
		ft_putstr(av[--i]);
		write(1, "\n", 1);
	}
	return (0);
}
