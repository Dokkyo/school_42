/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:56:45 by naben-za          #+#    #+#             */
/*   Updated: 2021/10/14 17:22:49 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isnumeric(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			 return (0);
		++i;
	}
	return (1);
}

void	signal_receipt(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("Server is receiving...\n", 1);
}

void	char_dismemberer(int pid, char c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i++))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Error with kill.\n", 1);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Error with kill.\n", 1);
				exit(EXIT_FAILURE);
			}
		}
		sleep(1);
	}
}

void	send_char(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		char_dismemberer(pid, str[i]);
		++i;
	}
	char_dismemberer(pid, 0);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac == 3)
	{
		if (!ft_isnumeric(av[1]))
		{
			ft_putstr_fd("Incorrect PID", 1);
			exit(EXIT_FAILURE);
		}
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = 0;
		sa.sa_handler = signal_receipt;
		sigaction(SIGUSR1, &sa, NULL);
		send_char(ft_atoi(av[1]), av[2]);
	}
	else
		ft_putstr_fd("Format is: ./client <PID> <STR>", 1);
	return (0);
}
