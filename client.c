/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:53:43 by amaso             #+#    #+#             */
/*   Updated: 2022/05/31 14:53:53 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//QUI DEVI ASPETTARE E RICEVERE IL SEGNALE DI FEEDBACK
void	send_string(char *str, int pid)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(str))
		send_bits(str[i], pid);
	free(str);
}

//SIGUSR1 = 0, SIGUSR2 = 1
void	send_bits(char c, int pid)
{
	int				i;
	unsigned int	bitmax;

	bitmax = 1 << (sizeof (int) * 8 - 1);
	i = 0;
	while (i < sizeof(char) * 8)
	{
		if (c & bitmax)
		{
			if (kill(pid, SIGUSR2) == -1)
				error_msg();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				error_msg();
		}
		c = c << 1;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	char				*str;
	int					i;

	i = -1;
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		kill(pid, SIGTERM);
		ft_putstr("Arguments are : [./client][pid][string]\n");
		ft_putstr("Error! Please check your parameters.\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	str = malloc (ft_strlen(argv[2]) + 1);
	while (++i < ft_strlen(argv[2]))
		str[i] = argv[2][i];
	str[i] = '\0';
	send_string(str, pid);
}
