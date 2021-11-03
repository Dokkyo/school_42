/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:13:38 by naben-za          #+#    #+#             */
/*   Updated: 2021/09/24 08:46:02 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi2(const char *nptr, t_Dlist **p_a, t_Dlist **p_b)
{
	int		i;
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
		{
			res = res * 10 + (nptr[i] - 48);
			i++;
		}
		else
			ft_puterr(p_a, p_b);
	}
	res *= sign;
	return (res);
}

long	check_value(char *str, t_Dlist **p_a, t_Dlist **p_b)
{
	long	nbr;

	nbr = ft_atoi2(str, p_a, p_b);
	if (nbr > 2147483647 || nbr < -2147483648)
		ft_puterr(p_a, p_b);
	return (nbr);
}

int	check_double(t_Dlist **p_list)
{
	size_t	i;
	size_t	j;
	int		tab[1000];

	if ((*p_list)->lenght >= 2)
	{
		i = -1;
		while (++i < (*p_list)->lenght)
		{
			tab[i] = (*p_list)->p_head->data;
			(*p_list)->p_head = (*p_list)->p_head->p_next;
		}
		i = -1;
		while (++i < (*p_list)->lenght)
		{
			j = i + 1;
			while (j < (*p_list)->lenght)
			{
				if (tab[i] == tab[j])
					return (1);
				++j;
			}
		}
	}
	return (0);
}

int	list_sorted(t_Dlist **p_list)
{
	size_t	i;
	size_t	j;
	int		tab[500];

	i = -1;
	while (++i < (*p_list)->lenght)
	{
		tab[i] = (*p_list)->p_head->data;
		(*p_list)->p_head = (*p_list)->p_head->p_next;
	}
	i = -1;
	while (++i < (*p_list)->lenght)
	{
		j = i + 1;
		while (j < (*p_list)->lenght)
		{
			if (tab[i] > tab[j])
				return (0);
			++j;
		}
	}
	return (1);
}

void	ft_free(t_Dlist **p_a, t_Dlist **p_b)
{
	dlist_delete(p_a);
	free(*p_b);
}
