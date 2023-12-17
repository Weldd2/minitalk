/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:55:12 by amura             #+#    #+#             */
/*   Updated: 2023/12/17 15:00:29 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	signal_handler(int signum)
{
	char	morse_char;

	if (signum == SIGUSR1)
		morse_char = '.';
	else
		morse_char = '-';
	write(1, &morse_char, 1);
}

int	main(void)
{
	struct sigaction	sa;

	printf("PID: %d\n", getpid());
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
