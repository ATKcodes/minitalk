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

//SIGUSR1 = 0, SIGUSR2 = 1
void	s_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int				i = 0;
	int						pid;
	static unsigned char	c = 0;

	(void)context;
	c |= (sig == SIGUSR1);
	pid = siginfo->si_pid;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	c = c << 1;
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
		error_msg("Error while receiving the signal");
	if (sigaction (SIGUSR2, &sa, NULL) == -1)
		error_msg("Error while receiving the signal");
	while (1)
		pause();
}
