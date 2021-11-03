/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:06:23 by naben-za          #+#    #+#             */
/*   Updated: 2021/10/12 16:09:44 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_random(t_Dlist **p_list)
{
	if ((*p_list)->p_head->data > (*p_list)->p_tail->data)
	{
		dlist_swap(p_list);
		ft_putstr("sa\n");
	}
}

void	three_random(t_Dlist **p_list)
{
	if ((*p_list)->p_head->data > (*p_list)->p_head->p_next->data
		&& (*p_list)->p_head->data < (*p_list)->p_tail->data)
		case_1(p_list);
	else if ((*p_list)->p_head->data > (*p_list)->p_head->p_next->data
		&& (*p_list)->p_tail->data < (*p_list)->p_head->p_next->data)
		case_2(p_list);
	else if ((*p_list)->p_head->data > (*p_list)->p_head->p_next->data
		&& (*p_list)->p_tail->data > (*p_list)->p_head->p_next->data)
		case_3(p_list);
	else if ((*p_list)->p_head->data < (*p_list)->p_head->p_next->data
		&& (*p_list)->p_head->data < (*p_list)->p_tail->data
		&& !list_sorted(p_list))
		case_4(p_list);
	else if (!list_sorted(p_list))
		case_5(p_list);
}

void	find_lowest(t_Dlist **p_list)
{
	size_t	lower_pos;
	size_t	middle;
	size_t	i;
	int		data;

	middle = (*p_list)->lenght / 2;
	i = 1;
	lower_pos = 0;
	data = (*p_list)->p_head->data;
	(*p_list)->p_head = (*p_list)->p_head->p_next;
	while (i < (*p_list)->lenght)
	{
		if ((*p_list)->p_head->data < data)
		{
			data = (*p_list)->p_head->data;
			lower_pos = i;
		}
		(*p_list)->p_head = (*p_list)->p_head->p_next;
		++i;
	}
	sort_with_instructions(&lower_pos, &middle, p_list);
}

void	four_five_random(t_Dlist **p_a, t_Dlist **p_b)
{
	while ((*p_a)->lenght != 3)
	{
		find_lowest(p_a);
		dlist_push(p_b, p_a);
		ft_putstr("pb\n");
	}
	three_random(p_a);
	dlist_pa_all(p_a, p_b);
}

void	sort_with_instructions(size_t *l_pos, size_t *mid, t_Dlist **p_list)
{
	if (*l_pos != 0)
	{
		if (*l_pos <= *mid)
		{
			while (*l_pos > 0)
			{
				dlist_rotate(p_list);
				ft_putstr("ra\n");
				*l_pos -= 1;
			}
		}
		else
		{
			while (*l_pos < (*p_list)->lenght)
			{
				dlist_rrotate(p_list);
				ft_putstr("rra\n");
				*l_pos += 1;
			}
		}
	}
}
