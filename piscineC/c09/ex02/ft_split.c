/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:38:00 by naben-za          #+#    #+#             */
/*   Updated: 2021/03/31 08:34:36 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		++charset;
	}
	return (0);
}

int		words_count(char *str, char *charset)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			words++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
		str++;
	}
	return (words);
}

void	ft_strcpy(char *dest, char *from, char *until)
{
	while (from < until)
		*(dest++) = *(from++);
	*dest = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**split_str;
	char	*from;
	int		i;

	if (!(split_str = malloc(sizeof(char*) * (words_count(str, charset) + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			from = str;
			while (*str && !is_charset(*str, charset))
				str++;
			if (!(split_str[i] = malloc(sizeof(char) * (str - from + 1))))
				return (NULL);
			ft_strcpy(split_str[i++], from, str);
		}
		str++;
	}
	split_str[i] = 0;
	return (split_str);
}
