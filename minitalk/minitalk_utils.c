/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:47:31 by sayar             #+#    #+#             */
/*   Updated: 2021/12/28 15:03:01 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_minitalk(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	check(int nbr, int sign)
{
	if (sign == '-')
		return (nbr * -1);
	else
		return (nbr);
}

int	ft_atoi(char *str)
{
	size_t	i;
	size_t	nbr;
	int		symb;

	symb = 1;
	i = 0;
	nbr = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		symb = str[i];
		i++;
	}
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (check(nbr, symb));
}

void	ft_putchar_solo(char c)
{
	write(1, &c, 1);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;
	char	*nsrc;

	i = 0;
	nsrc = (char *) src;
	len = ft_strlen(nsrc);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	while (nsrc[i])
	{
		str[i] = nsrc[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
