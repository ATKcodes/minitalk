/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:25:13 by amaso             #+#    #+#             */
/*   Updated: 2022/05/31 14:54:31 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	sigusr2_handler(int sig);
void	sigusr1_handler(int sig);

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	error_msg(void);

void	send_bits(char c, int pid);
void	send_string(char *str, int pid);

#endif
