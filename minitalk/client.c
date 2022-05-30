/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:32:43 by sayar             #+#    #+#             */
/*   Updated: 2021/12/28 16:33:33 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	int	pid;
	int	i;

	if (ac != 3)
		return (ft_putstr_minitalk("Not enough Args"), 1);
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
