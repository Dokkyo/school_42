/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:34:47 by naben-za          #+#    #+#             */
/*   Updated: 2021/04/01 10:57:13 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_check_base(char *base)
{
	int		i;
	int		j;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32 ||
		base[i] == '+' || base[i] == '-' || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_inbase(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int			sign;
	long int	nb;
	int			j;

	sign = 1;
	while (*str <= 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nb = 0;
	if (ft_check_base(base))
	{
		while ((j = ft_inbase(*str, base)) >= 0)
		{
			nb = nb * ft_strlen(base) + j;
			str++;
		}
	}
	return (nb * sign);
}
