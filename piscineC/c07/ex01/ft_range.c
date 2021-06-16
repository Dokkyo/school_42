/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:23:14 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/25 08:56:46 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	tab = NULL;
	if (min >= max)
		return (tab);
	if (!(tab = malloc(sizeof(int) * (max - min))))
		return (NULL);
	i = -1;
	while (min < max)
		tab[++i] = min++;
	return (tab);
}
