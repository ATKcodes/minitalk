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

//SIGUSR1 = 0, SIGUSR2 = 1
void	send_bits(char c, int pid)
{
	int				i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_msg("Wrong PID!");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_msg("Wrong PID!");
		}
		usleep(100);
	}
}

void	send_string(char *str, int pid)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(str))
	{
		send_bits(str[i], pid);
	}
	free(str);
}

void	c_handler(int sig)
{
	static int	c;

	if (sig == SIGUSR1)
		c++;
	else
		c++;
	ft_putstr("printed a total of ");
	ft_putnbr(c);
	ft_putstr(" characters\n");
	usleep(69);
}

int	main(int argc, char *argv[])
{
	int					pid;
	char				*str;
	int					i;

	i = -1;
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr("Error! Please check your parameters.\n");
		ft_putstr("Arguments are : [./client][pid][string]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	str = malloc (ft_strlen(argv[2]) + 1);
	while (++i < ft_strlen(argv[2]))
		str[i] = argv[2][i];
	str[i] = '\0';
	signal(SIGUSR1, c_handler);
	send_string(str, pid);
	while (1)
		pause();
}
