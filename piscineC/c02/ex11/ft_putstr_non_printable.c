/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:10:12 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/18 15:57:37 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*base;

	base = "0123456789abcdef";
	while (*str)
	{
		if (*str < 32 || *str > 126)
		{
			write(1, "\\", 1);
			write(1, &base[(unsigned char)*str / 16], 1);
			write(1, &base[(unsigned char)*str % 16], 1);
			str++;
		}
		else
		{
			write(1, &*str, 1);
			str++;
		}
	}
}
