/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:03:03 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/25 08:55:43 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int dif;

	i = 0;
	dif = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!(*range = malloc(sizeof(int) * dif)))
		return (-1);
	while (i < dif)
	{
		(*range)[i++] = min++;
	}
	return (i);
}
