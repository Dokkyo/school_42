/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 08:30:33 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/23 16:37:18 by naben-za         ###   ########.fr       */
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

	(void)ac;
	i = 0;
	while (av[++i])
	{
		ft_putstr(av[i]);
		write(1, "\n", 1);
	}
	return (0);
}
