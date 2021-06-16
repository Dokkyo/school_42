/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:09:40 by naben-za          #+#    #+#             */
/*   Updated: 2021/02/04 08:47:08 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char lettre;

	lettre = 'a';
	while (lettre <= 'z')
	{
		write(1, &lettre, 1);
		lettre++;
	}
}
