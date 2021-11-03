/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:25:51 by naben-za          #+#    #+#             */
/*   Updated: 2021/09/13 13:27:22 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlist_swap1(t_Dlist **p_list, struct s_node *tmp3)
{
	if ((*p_list)->lenght == 2)
	{
		(*p_list)->p_tail = (*p_list)->p_head->p_next;
		(*p_list)->p_head->p_prev = (*p_list)->p_tail;
		(*p_list)->p_tail->p_next = (*p_list)->p_head;
		(*p_list)->p_tail->p_prev = (*p_list)->p_head;
	}
	else if ((*p_list)->lenght == 3)
	{
		(*p_list)->p_tail->p_next = (*p_list)->p_head;
		(*p_list)->p_tail->p_prev = (*p_list)->p_head->p_next;
		(*p_list)->p_head->p_next->p_next = (*p_list)->p_tail;
		(*p_list)->p_head->p_prev = (*p_list)->p_tail;
	}
	else
	{
		(*p_list)->p_head->p_next->p_next = tmp3;
		(*p_list)->p_head->p_next->p_next->p_prev = (*p_list)->p_head->p_next;
		(*p_list)->p_tail->p_next = (*p_list)->p_head;
		(*p_list)->p_head->p_prev = (*p_list)->p_tail;
	}
}

void	dlist_swap(t_Dlist **p_list)
{
	struct s_node	*tmp1;
	struct s_node	*tmp2;
	struct s_node	*tmp3;

	if (*p_list != NULL && (*p_list)->lenght >= 2)
	{
		tmp1 = (*p_list)->p_head;
		tmp2 = (*p_list)->p_head->p_next;
		tmp3 = (*p_list)->p_head->p_next->p_next;
		(*p_list)->p_head = tmp2;
		(*p_list)->p_head->p_next = tmp1;
		(*p_list)->p_head->p_next->p_prev = (*p_list)->p_head;
		dlist_swap1(p_list, tmp3);
	}
}

void	dlist_rotate(t_Dlist **p_list)
{
	struct s_node	*tmp1;
	struct s_node	*tmp2;
	struct s_node	*tmp3;

	if ((*p_list)->lenght > 1)
	{
		tmp1 = (*p_list)->p_head;
		tmp2 = (*p_list)->p_head->p_next;
		tmp3 = (*p_list)->p_tail;
		(*p_list)->p_head = tmp2;
		(*p_list)->p_tail = tmp1;
		(*p_list)->p_head->p_prev = (*p_list)->p_tail;
		(*p_list)->p_tail->p_next = (*p_list)->p_head;
		(*p_list)->p_head->p_next->p_prev = (*p_list)->p_head;
		if ((*p_list)->lenght == 2)
			(*p_list)->p_tail->p_prev = (*p_list)->p_head;
		(*p_list)->p_tail->p_prev = tmp3;
	}
}

void	dlist_rrotate(t_Dlist **p_list)
{
	struct s_node	*tmp1;
	struct s_node	*tmp2;

	if ((*p_list)->lenght > 1)
	{
		tmp1 = (*p_list)->p_tail;
		tmp2 = (*p_list)->p_tail->p_prev;
		(*p_list)->p_head = tmp1;
		(*p_list)->p_tail = tmp2;
		(*p_list)->p_tail->p_next = (*p_list)->p_head;
		(*p_list)->p_head->p_next->p_prev = (*p_list)->p_head;
	}
}
