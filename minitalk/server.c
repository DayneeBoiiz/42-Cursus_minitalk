/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:53:53 by sayar             #+#    #+#             */
/*   Updated: 2021/12/30 09:58:40 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int check)
{
	static char	*store;

	if (check == SIGUSR1)
		store = ft_strjoin(store, "1");
	if (check == SIGUSR2)
		store = ft_strjoin(store, "0");
	if (ft_strlen(store) == 8)
	{
		ft_putchar_solo(convert_to_decimal(ft_atoi(store)));
		store = NULL;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)av;
	if (ac != 1)
	{
		write(1, "Wrong arguments\n", 16);
		return (1);
	}
	pid = getpid();
	ft_putstr_minitalk("********** Server Started **********\n");
	ft_putstr_minitalk("************************************\n");
	ft_putstr_minitalk("PID :");
	ft_putnbr(pid);
	write(1, "\n", 1);
	if ((signal(SIGUSR1, signal_handler)) < 0)
		write(1, "Error recieving the signal\n", 27);
	if ((signal(SIGUSR2, signal_handler)) < 0)
		write(1, "Error recieving the signal\n", 27);
	while (1)
		pause();
}
