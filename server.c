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
void	s_handler(int sig, siginfo_t siginfo, void *opt)
{
	static int	i;
	int			pid;
	static char	c;

	(void)opt;
	pid = siginfo.si_pid;
	i++;

	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = &s_handler;
	if (sigaction (SIGUSR1, &sa, NULL) == -1)
		error_msg();
	if (sigaction (SIGUSR2, &sa, NULL) == -1)
		error_msg();
	pid = getpid();
	printf("pid : %d", pid);
//	while(1)
//	{
//		usleep(500);
//	}
}
