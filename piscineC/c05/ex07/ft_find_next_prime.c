/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:22:31 by marvin            #+#    #+#             */
/*   Updated: 2021/02/22 15:34:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 1)
	{
		while (i <= nb / i)
		{
			if (i * (nb / i) == nb)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	while (ft_is_prime(nb) == 0)
		nb++;
	if (ft_is_prime(nb) == 1)
		return (nb);
	return (0);
}
