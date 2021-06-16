/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:16:52 by naben-za          #+#    #+#             */
/*   Updated: 2021/02/05 17:25:18 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	print_comb_output(char a, char b, char c)
{
	putchar(a);
	putchar(b);
	putchar(c);
	if (a != '7')
	{
		putchar(',');
		putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				print_comb_output(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
