/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 08:30:33 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/29 12:19:04 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen_in_strs(char **strs)
{
	int i;

	i = 0;
	while ((*strs)[i] != '\0')
		++i;
	return (i);
}

char				*ft_strdup(char *src, int size)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*tab;
	int				i;

	if (!(tab = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen_in_strs(&av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(tab[i].str, tab[i].size);
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}
