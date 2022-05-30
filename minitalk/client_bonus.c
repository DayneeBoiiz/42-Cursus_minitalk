/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:11:35 by sayar             #+#    #+#             */
/*   Updated: 2021/12/30 09:56:08 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_recieved(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_minitalk("Message Received\n");
}

void	send_bits(char c, int pid)
{
	int		i;
	char	x;

	i = 7;
	while (i >= 0)
	{
		x = c >> i-- & 1;
		if (x == 1)
			kill(pid, SIGUSR1);
		else if (x == 0)
			kill(pid, SIGUSR2);
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	signal(SIGUSR1, ft_recieved);
	if (ac != 3)
	{
		ft_putstr_minitalk("Wrong Args!!");
		return (1);
	}
	else
	{
		i = 0;
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			send_bits(av[2][i], pid);
			i++;
		}
		if (av[2][i] == '\0')
		{
			send_bits(av[2][i], pid);
			sleep(1);
		}
	}
	return (0);
}
