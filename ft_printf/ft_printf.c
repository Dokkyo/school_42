/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:27:05 by naben-za          #+#    #+#             */
/*   Updated: 2021/08/09 16:02:23 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_percent_conversion(char c, size_t *len)
{
	if (c == 'c')
		c_conv();
	else
		ft_putchar(c);
	*len += 1;
}

char	*other_conversion(char c)
{
	char	*str;

	if (c == 's')
		s_conv(&str);
	else if (c == 'p')
		p_conv(&str);
	else if (c == 'd' || c == 'i')
		di_conv(&str);
	else if (c == 'u')
		ux_conv(&str, BASE_10);
	else if (c == 'x')
		ux_conv(&str, BASE_16_LOWER);
	else if (c == 'X')
		ux_conv(&str, BASE_16_UPPER);
	else
		str = NULL;
	return (str);
}

void	fmt_parser(const char *fmt, char *str, size_t *len)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			if (*fmt == 'c' || *fmt == '%')
				c_percent_conversion(*fmt, &*len);
			else
			{
				str = other_conversion(*fmt);
				ft_putstr(str);
				*len += ft_strlen(str);
				free(str);
			}
			++fmt;
		}
		else
		{
			ft_putchar(*fmt);
			fmt++;
			*len += 1;
		}
	}
}

int	ft_printf(const char *fmt, ...)
{
	size_t		c_printed;

	c_printed = 0;
	va_start(g_ap, fmt);
	fmt_parser(fmt, 0, &c_printed);
	va_end(g_ap);
	return (c_printed);
}
