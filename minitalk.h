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
# include <stdarg.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	error_msg(char *str);
void	ft_putnbr(int nb);

#endif
