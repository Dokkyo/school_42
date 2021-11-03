/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:11:36 by naben-za          #+#    #+#             */
/*   Updated: 2021/09/13 13:45:33 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlist_push1(t_Dlist **p_list, struct s_node *p_tmpa)
{
	if ((*p_list)->lenght == 1)
	{
		(*p_list)->p_tail = (*p_list)->p_head;
		(*p_list)->p_head->p_next = (*p_list)->p_head;
		(*p_list)->p_head->p_prev = (*p_list)->p_tail;
	}
	else if ((*p_list)->lenght == 2)
	{
		(*p_list)->p_head->p_next = p_tmpa;
		(*p_list)->p_tail = (*p_list)->p_head->p_next;
		(*p_list)->p_head->p_prev = (*p_list)->p_tail;
		(*p_list)->p_tail->p_prev = (*p_list)->p_head;
		(*p_list)->p_tail->p_next = (*p_list)->p_head;
	}
	else if ((*p_list)->lenght == 3)
	{
		(*p_list)->p_head->p_next = p_tmpa;
		(*p_list)->p_head->p_prev = (*p_list)->p_tail;
		(*p_list)->p_head->p_next->p_prev = (*p_list)->p_head;
		(*p_list)->p_tail->p_next = (*p_list)->p_head;
	}
}

void	dlist_push2(t_Dlist **p_list, struct s_node *p_tmpb2)
{
	if ((*p_list)->lenght == 0)
	{
		(*p_list)->p_head = NULL;
		(*p_list)->p_tail = NULL;
	}
	else if ((*p_list)->lenght == 1)
	{
		(*p_list)->p_head = p_tmpb2;
		(*p_list)->p_tail = (*p_list)->p_head;
		(*p_list)->p_tail->p_prev = (*p_list)->p_head;
		(*p_list)->p_tail->p_next = (*p_list)->p_head;
	}
	else
	{
		(*p_list)->p_head = p_tmpb2;
		(*p_list)->p_head->p_prev = (*p_list)->p_tail;
		(*p_list)->p_head->p_next->p_prev = (*p_list)->p_head;
		(*p_list)->p_tail->p_next = (*p_list)->p_head;
	}
}

void	dlist_push(t_Dlist **p_list1, t_Dlist **p_list2)
{
	struct s_node	*p_tmpa;
	struct s_node	*p_tmpb1;
	struct s_node	*p_tmpb2;

	if ((*p_list2)->p_tail != NULL)
	{
		p_tmpa = (*p_list1)->p_head;
		p_tmpb1 = (*p_list2)->p_head;
		p_tmpb2 = (*p_list2)->p_head->p_next;
		(*p_list1)->p_head = p_tmpb1;
		(*p_list1)->lenght += 1;
		(*p_list2)->lenght -= 1;
		if ((*p_list1)->lenght == 1 || (*p_list1)->lenght == 2
			|| (*p_list1)->lenght == 3)
			dlist_push1(p_list1, p_tmpa);
		else
		{
			(*p_list1)->p_head->p_next = p_tmpa;
			(*p_list1)->p_head->p_prev = (*p_list1)->p_tail;
			(*p_list1)->p_head->p_next->p_prev = (*p_list1)->p_head;
			(*p_list1)->p_tail->p_next = (*p_list1)->p_head;
		}
		dlist_push2(p_list2, p_tmpb2);
	}
}
