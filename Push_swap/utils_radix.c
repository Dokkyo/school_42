/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:46:18 by naben-za          #+#    #+#             */
/*   Updated: 2021/09/24 08:48:18 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_copy(t_Dlist **p_list)
{
	int		*copy;
	size_t	j;

	copy = malloc(sizeof(*copy) * (*p_list)->lenght);
	if (copy != NULL)
	{
		j = 0;
		while (j < (*p_list)->lenght)
		{
			copy[j] = (*p_list)->p_head->data;
			++j;
			(*p_list)->p_head = (*p_list)->p_head->p_next;
		}
	}
	return (copy);
}

void	sort_copy(int *tab, t_Dlist **p_a)
{
	size_t	j;
	size_t	k;
	int		tmp;

	j = 0;
	while (j < (*p_a)->lenght)
	{
		k = j + 1;
		while (k < (*p_a)->lenght)
		{
			if (tab[k] < tab[j])
			{
				tmp = tab[k];
				tab[k] = tab[j];
				tab[j] = tmp;
			}
			++k;
		}
		++j;
	}
}

void	set_index(t_Dlist **p_a, int *tab)
{
	size_t	j;
	size_t	k;

	j = 0;
	while (j < (*p_a)->lenght)
	{
		k = 0;
		while (k < (*p_a)->lenght)
		{
			if ((*p_a)->p_head->data == tab[k])
				(*p_a)->p_head->index = k;
			++k;
		}
		(*p_a)->p_head = (*p_a)->p_head->p_next;
		++j;
	}
}
