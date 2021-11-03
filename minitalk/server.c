/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:57:13 by naben-za          #+#    #+#             */
/*   Updated: 2021/10/14 17:22:51 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strchar_join(char *s, char c)
{
	char	*str;
	int		i;

	i = ft_strlen(s) + 2;
	str = malloc(sizeof(char *) * (ft_strlen(s) + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		str[i] = s[i];
		++i;
	}
	str[i++] = c;
	str[i] = 0;
	if (s)
		free(s);
	return (str);
}

int	char_memberer(int sig, char *c)
{
	static int	i;

	if (i == 8)
	{
		i = 0;
		*c = 0;
	}
	if (i < 8)
	{
		if (sig == SIGUSR1)
			*c |= (1 << i++);
		else if (sig == SIGUSR2)
			*c |= (0 << i++);
	}
	return (i);
}

void	signal_handler(int sig, siginfo_t *info, void *unused)
{
	static char	*str;
	static char	c;
	int			i;

	(void)unused;
	i = char_memberer(sig, &c);
	if (i == 8 && c)
		str = ft_strchar_join(str, c);
	else if (i == 8 && !c)
	{
		ft_putstr_fd(str, 1);
		free(str);
		str = NULL;
	}
	usleep(300);
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac == 1)
	{
		ft_putstr_fd("Server PID: ", 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putstr_fd("\n", 1);
		if (sigemptyset(&sa.sa_mask) == -1
			|| sigaddset(&sa.sa_mask, SIGUSR1) == -1
			||sigaddset(&sa.sa_mask, SIGUSR2) == -1)
			ft_putstr_fd("Sigset error\n", 1);
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = signal_handler;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	return (0);
}
