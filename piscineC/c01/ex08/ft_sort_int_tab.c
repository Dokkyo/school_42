/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:51:37 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/16 11:29:52 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
	}
}
