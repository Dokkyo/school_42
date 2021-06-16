/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:14:02 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/18 09:49:10 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isalphanum(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
	|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || !isalphanum(str[i - 1]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			i++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}
