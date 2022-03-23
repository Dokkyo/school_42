/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:02:21 by naben-za          #+#    #+#             */
/*   Updated: 2022/03/23 11:03:52 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_nbr_error(void)
{
	printf("Invalid number of arguments.\n");
	exit(1);
}

void	args_syntax_error(int ac)
{
	printf("arg syntax number %d is incorrect.\n", ac);
	exit(2);
}

void	allocation_error(void)
{
	printf("Allocation failed.\n");
	exit(3);
}
