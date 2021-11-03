/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:34:15 by naben-za          #+#    #+#             */
/*   Updated: 2021/09/13 12:44:59 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Dlist	*dlist_new(void)
{
	t_Dlist		*p_new;

	p_new = malloc(sizeof(*p_new));
	if (p_new == NULL)
	{
		ft_putstr("Allocation failed");
		exit(EXIT_FAILURE);
	}
	p_new->lenght = 0;
	p_new->p_head = NULL;
	p_new->p_tail = NULL;
	return (p_new);
}

void	dlist_append2(t_Dlist **p_list, int data, struct s_node **p_new)
{
	(*p_new)->data = data;
	(*p_new)->p_next = NULL;
	if ((*p_list)->p_tail == NULL)
	{
		(*p_new)->p_prev = NULL;
		(*p_list)->p_head = *p_new;
		(*p_list)->p_tail = *p_new;
	}
	else
	{
		(*p_list)->p_tail->p_next = *p_new;
		(*p_new)->p_prev = (*p_list)->p_tail;
		(*p_new)->p_next = (*p_list)->p_head;
		(*p_list)->p_tail = *p_new;
	}
	(*p_list)->lenght++;
}

int	dlist_append(t_Dlist *p_list, int data)
{
	struct s_node	*p_new;

	if (p_list != NULL)
	{
		p_new = malloc(sizeof(*p_new));
		if (p_new == NULL)
		{
			ft_putstr("Allocation failed");
			return (-1);
		}
		dlist_append2(&p_list, data, &p_new);
	}
	return (1);
}

void	dlist_delete(t_Dlist **p_list)
{
	struct s_node	*p_temp;
	struct s_node	*p_del;
	size_t			lenght;
	size_t			i;

	i = -1;
	lenght = (*p_list)->lenght;
	if (*p_list != NULL)
	{
		p_temp = (*p_list)->p_head;
		while (++i < lenght)
		{
			p_del = p_temp;
			p_temp = p_temp->p_next;
			free(p_del);
		}
		free(*p_list);
		p_list = NULL;
	}
}
