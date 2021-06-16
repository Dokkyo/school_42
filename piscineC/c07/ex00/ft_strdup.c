/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:48:04 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/31 08:49:46 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	i = 0;
	while (*src)
		str[i++] = *src++;
	str[i] = '\0';
	return (str);
}
