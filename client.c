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


// CONTINUA QUI DA SEND BITS, MANDA I BITS 1 PER UNO, POI FALLO CON SIGUSR1,2
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	send_bits(char *str)
{

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
	str = malloc (ft_strlen (argv[3]) + 1);
	while (++i < ft_strlen ((argv[3]) + 1))
		str = argv[3][i];
	
}
