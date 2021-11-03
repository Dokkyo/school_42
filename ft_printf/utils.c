/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 05:06:31 by naben-za          #+#    #+#             */
/*   Updated: 2021/08/09 14:49:20 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_putstr(char *s)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}
