/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:30:33 by naben-za          #+#    #+#             */
/*   Updated: 2021/02/05 17:23:40 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int c1;
	int c2;

	c1 = 0;
	while (c1 < 99)
	{
		c2 = c1 + 1;
		while (c2 < 100)
		{
			ft_putchar('0' + c1 / 10);
			ft_putchar('0' + c1 % 10);
			ft_putchar(' ');
			ft_putchar('0' + c2 / 10);
			ft_putchar('0' + c2 % 10);
			if (c1 != 98)
			{
				write(1, ", ", 2);
			}
			c2++;
		}
		c1++;
	}
}
