/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:59:25 by naben-za          #+#    #+#             */
/*   Updated: 2022/03/04 14:21:00 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_Dlist	*dlist_new(void)
{
	t_Dlist	*p_new;

	p_new = malloc(sizeof(*p_new));
	if (p_new == NULL)
	{
		ft_putstr_fd("List Allocation failed", 1);
		exit(EXIT_FAILURE);
	}
	p_new->width = 0;
	p_new->height = 0;
	p_new->lenght = 0;
	p_new->p_head = NULL;
	p_new->p_tail = NULL;
	return (p_new);
}

void	dlist_append(t_Dlist *p_list, char *nbr)
{
	struct s_node	*p_new;

	if (p_list != NULL)
	{
		p_new = malloc(sizeof(*p_new));
		if (p_new == NULL)
			ft_error1(&p_list);
		p_new->z = ft_atoi(nbr);
		p_new->p_next = NULL;
		if (p_list->p_head == NULL)
		{
			p_list->p_head = p_new;
			p_list->p_tail = p_new;
		}
		else
		{
			p_list->p_tail->p_next = p_new;
			p_list->p_tail = p_new;
		}
	}
	p_list->lenght++;
}

void	ft_getnbr(char **tab, t_Dlist *p_list)
{
	int	i;

	i = 0;
	while (i < p_list->width)
	{
		dlist_append(p_list, tab[i]);
		++i;
	}
}

int	count_nbr(char const *s, char c)
{
	int	nbr;

	nbr = 0;
	while (*s)
	{
		if (*s != c)
		{
			nbr++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (nbr);
}
