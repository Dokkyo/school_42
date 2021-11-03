/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:50:35 by naben-za          #+#    #+#             */
/*   Updated: 2021/09/13 12:03:31 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		++i;
	}
}

void	ft_puterr(t_Dlist **p_a, t_Dlist **p_b)
{
	ft_free(p_a, p_b);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
