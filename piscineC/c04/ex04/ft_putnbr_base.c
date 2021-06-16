/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:35:26 by naben-za          #+#    #+#             */
/*   Updated: 2021/04/01 10:57:30 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		ft_checkbase(char *base)
{
	int	j;
	int	i;

	if (!base || ft_strlen(base) <= 1)
		return (0);
	j = 0;
	while (base[j])
	{
		if (base[j] == '+' || base[j] == '-' || base[j] < 32 || base[j] > 126)
			return (0);
		i = j + 1;
		while (base[i])
		{
			if (base[j] == base[i])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;
	int			len;

	len = ft_strlen(base);
	nb = nbr;
	if (ft_checkbase(base) == 1)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		if (nb >= len)
			ft_putnbr_base(nb / len, base);
		write(1, &base[nb % len], 1);
	}
}
