/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:54:04 by amaso             #+#    #+#             */
/*   Updated: 2022/05/31 14:54:36 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
//CONTINUA QUI CON LA RICEZIONE DEI SEGNALI E MANDANDO UN FEEDBACK
//SIGUSR1 = 0, SIGUSR2 = 1

void	ft_putnbr(int nb)
{
	char	l;

	if (nb == -2147483648)
	{
		ft_putnbr((nb / 10));
		write(1, "8", 1);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			ft_putnbr((nb / 10));
		l = 48 + nb % 10;
		write(1, &l, 1);
	}
}

void	s_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int		i;
	int				pid;
	unsigned char	c;
	int				bit;

	if (i == 0)
		c = 'A' >> 7;
	(void)context;
	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	c += bit >> i;
	pid = siginfo->si_pid;
	i++;
	ft_putnbr(i);
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = s_handler;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	if (sigaction (SIGUSR1, &sa, NULL) == -1)
		error_msg();
	if (sigaction (SIGUSR2, &sa, NULL) == -1)
		error_msg();
	while (1)
		pause();
}
