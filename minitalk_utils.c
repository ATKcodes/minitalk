/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:02:15 by amaso             #+#    #+#             */
/*   Updated: 2022/03/27 00:42:25 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	long	r;

	r = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] <= '9' && '0' <= str[i])
	{
		r = r * 10 + str[i] - '0';
		if (r < -2147483648 || r > 2147483647)
			return ((r < -2147483648) - 1);
		i++;
	}
	return (r);
}

void	error_msg(void)
{
	ft_putstr("Wrong PID!");
	exit(1);
}
