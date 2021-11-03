/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:44:36 by naben-za          #+#    #+#             */
/*   Updated: 2021/10/12 16:07:38 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlist_pa_all(t_Dlist **p_a, t_Dlist **p_b)
{
	while ((*p_b)->lenght > 0)
	{
		dlist_push(p_a, p_b);
		ft_putstr("pa\n");
	}
}

void	radix(t_Dlist **p_a, t_Dlist **p_b, int max_bits, size_t len)
{
	int		i;
	size_t	l;
	int		num;

	i = -1;
	while (++i < max_bits)
	{
		l = -1;
		while (++l < len)
		{
			num = (*p_a)->p_head->index;
			if ((num >> i & 1) == 1)
			{
				dlist_rotate(p_a);
				ft_putstr("ra\n");
			}
			else
			{
				dlist_push(p_b, p_a);
				ft_putstr("pb\n");
			}
		}
		dlist_pa_all(p_a, p_b);
	}
}

void	launch_radix(t_Dlist **p_a, t_Dlist **p_b)
{
	int		*tab;
	int		max_num;
	int		max_bits;
	size_t	len;

	len = (*p_a)->lenght;
	tab = create_copy(p_a);
	sort_copy(tab, p_a);
	set_index(p_a, tab);
	max_num = (*p_a)->lenght - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	radix(p_a, p_b, max_bits, len);
	free(tab);
}

void	launch_algo(t_Dlist **p_a, t_Dlist **p_b)
{
	if (check_double(p_a))
		ft_puterr(p_a, p_b);
	else if (list_sorted(p_a))
	{
		ft_free(p_a, p_b);
		exit(EXIT_SUCCESS);
	}
	else if ((*p_a)->lenght == 2)
		two_random(p_a);
	else if ((*p_a)->lenght == 3)
		three_random(p_a);
	else if ((*p_a)->lenght <= 5)
		four_five_random(p_a, p_b);
	else
		launch_radix(p_a, p_b);
}

int	main(int ac, char **av)
{
	t_Dlist	*p_a;
	t_Dlist	*p_b;
	char	*str;
	int		i;
	long	nbr;

	if (ac >= 3)
	{
		i = 1;
		p_a = dlist_new();
		p_b = dlist_new();
		while (i < ac)
		{
			str = av[i];
			nbr = check_value(str, &p_a, &p_b);
			if (dlist_append(p_a, nbr) == -1)
				ft_puterr(&p_a, &p_b);
			++i;
		}
		launch_algo(&p_a, &p_b);
		ft_free(&p_a, &p_b);
	}
	return (0);
}
