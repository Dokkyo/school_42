/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_random_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:01:42 by naben-za          #+#    #+#             */
/*   Updated: 2021/09/13 12:56:57 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_1(t_Dlist **p_list)
{
	dlist_swap(p_list);
	ft_putstr("sa\n");
}

void	case_2(t_Dlist **p_list)
{
	dlist_swap(p_list);
	dlist_rrotate(p_list);
	ft_putstr("sa\nrra\n");
}

void	case_3(t_Dlist **p_list)
{
	dlist_rotate(p_list);
	ft_putstr("ra\n");
}

void	case_4(t_Dlist **p_list)
{
	dlist_swap(p_list);
	dlist_rotate(p_list);
	ft_putstr("sa\nra\n");
}

void	case_5(t_Dlist **p_list)
{
	dlist_rrotate(p_list);
	ft_putstr("rra\n");
}
