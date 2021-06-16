/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:06:44 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/22 15:55:04 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (*dest)
	{
		++dest;
		++i;
	}
	while (*src && i + 1 < size)
	{
		*dest = *src;
		++src;
		++dest;
		++i;
	}
	if (i < size)
		*dest = '\0';
	while (*src)
	{
		++src;
		++i;
	}
	return (i);
}
