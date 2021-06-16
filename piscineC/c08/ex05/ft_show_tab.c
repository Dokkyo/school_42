/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:50:47 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/29 12:18:24 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int nb)
{
	if (nb > 9)
		putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		putstr(par[i].str);
		write(1, "\n", 1);
		putnbr(par[i].size);
		write(1, "\n", 1);
		putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
