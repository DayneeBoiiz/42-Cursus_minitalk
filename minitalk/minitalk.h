/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:49:18 by sayar             #+#    #+#             */
/*   Updated: 2021/12/28 15:05:10 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	signalhandler(int pid);
void	ft_putstr_minitalk(char *str);
char	*ft_strdup(char *src);
void	send_bits(char c, int pid);
int		ft_atoi(char *str);
int		check(int nbr, int sign);
int		ft_strlen(char *str);
int		convert_to_decimal(int binary);
char	*ft_strjoin(char *s1, char *s2);
void	signal_handler(int check);
void	ft_putchar_solo(char c);
void	ft_putnbr(int nb);

#endif
