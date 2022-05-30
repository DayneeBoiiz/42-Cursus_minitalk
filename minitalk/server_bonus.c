/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:11:23 by infoyar           #+#    #+#             */
/*   Updated: 2021/12/30 09:58:08 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdio.h>

pid_t	g_pid;

int	convert_to_decimall(int binary)
{
	int	decimal;
	int	base;
	int	rem;
	int	num;

	decimal = 0;
	base = 1;
	num = binary;
	while (binary != 0)
	{
		rem = binary % 10;
		decimal = decimal + rem * base;
		binary = binary / 10;
		base = base * 2;
	}
	if (decimal == 0)
		kill(g_pid, SIGUSR1);
	return (decimal);
}

void	signal_handler(int check, siginfo_t *info, void *content)
{
	static char	*store;

	(void)content;
	g_pid = info->si_pid;
	if (check == SIGUSR1)
		store = ft_strjoin(store, "1");
	if (check == SIGUSR2)
		store = ft_strjoin(store, "0");
	if (ft_strlen(store) == 8)
	{
		ft_putchar_solo(convert_to_decimall(ft_atoi(store)));
		store = NULL;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	info;
	static int			pid;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_minitalk("Wrong Args!!!");
		return (1);
	}
	pid = getpid();
	ft_putstr_minitalk("********** Server Started **********\n");
	ft_putstr_minitalk("************************************\n");
	ft_putstr_minitalk("PID :");
	ft_putnbr(pid);
	write(1, "\n", 1);
	info.sa_flags = SA_SIGINFO;
	info.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	while (1)
		pause();
}
