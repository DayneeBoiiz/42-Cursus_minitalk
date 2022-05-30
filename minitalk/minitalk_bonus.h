/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:13:54 by sayar             #+#    #+#             */
/*   Updated: 2021/12/28 15:05:37 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

char	*ft_strjoin(char *s1, char *s2);
int		convert_to_decimal(int binary);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
char	*ft_strdup(char *src);
void	ft_putchar_solo(char c);
int		ft_atoi(char *str);
int		check(int nbr, int sign);
void	ft_putstr_minitalk(char *str);

#endif
