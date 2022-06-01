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

#include "minitalk_h"

//QUI DEVI ASPETTARE E RICEVERE IL SEGNALE DI FEEDBACK
void	send_string(char *str, int pid)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(str))
		send_bits(str[i], pid);
}

//SIGUSR1 = 0, SIGUSR2 = 1
void	send_bits(char c, int pid)
{
    int             i;
    unsigned int    bitMax;

    bitMax = 1<<(sizeof(int)*8-1);
    i = 0;
	while (i < sizeof(char))
    {
		if (c&bitMax)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c<<1;
    	i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	int		i;

	i = -1;
	pid = ft_atoi(argv[2]);
	if (argc < 3 || argc > 3)
	{
		kill(pid);
		ft_putstr("Error! Please check your parameters.");
		return (0);
	}
	str = malloc (ft_strlen(argv[3]) + 1);
	while (++i < ft_strlen((argv[3]) + 1))
		str = argv[3][i];
	send_string(str, pid);
}
