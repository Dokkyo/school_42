/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 09:25:37 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/23 16:36:17 by naben-za         ###   ########.fr       */
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

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (++i < ac - 1)
	{
		j = i;
		while (++j < ac)
		{
			if (ft_strcmp(av[i], av[j]) > 0)
			{
				tmp = av[i];
				av[i] = av[j];
				av[j] = tmp;
			}
		}
	}
	i = 0;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		write(1, "\n", 1);
	}
	return (0);
}
