/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:05:23 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/22 15:56:59 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (dest[i])
		i++;
	while (*src && n < nb)
	{
		dest[i++] = *src++;
		n++;
	}
	dest[i] = '\0';
	return (dest);
}
