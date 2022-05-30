/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:31:43 by sayar             #+#    #+#             */
/*   Updated: 2021/12/28 15:03:28 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
			str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

int	convert_to_decimal(int binary)
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
	if (decimal > 127 || decimal < 0)
	{
		write(1, "\nError Recieving the signal\n", 28);
		exit(0);
	}
	else
		return (decimal);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar_solo(nb + '0');
	}
	else if (nb < 0)
	{
		ft_putchar_solo('-');
		if (nb == -2147483648)
		{
			ft_putchar_solo('2');
			ft_putnbr(147483648);
		}
		else
		{
			ft_putnbr(nb *(-1));
		}
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
