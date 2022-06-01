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
void	sigusr1_handler()
{
	
}

int main ()
{
	int	pid;

	pid = getpid();
	printf("pid : %d", pid);
//	while(1)
//	{
//		usleep(500);
//	}
}
