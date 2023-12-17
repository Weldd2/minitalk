/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:55:17 by amura             #+#    #+#             */
/*   Updated: 2023/12/17 14:58:19 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	send_morse(pid_t pid, char *morse_code)
{
	int	i;
	int	signal;

	i = 0;
	signal = 0;
	while (morse_code[i] != '\0')
	{
		if (morse_code[i] == '.')
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		kill(pid, signal);
		usleep(100000);
		i++;
	}
	usleep(300000);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s <pid> <morse_code>\n", argv[0]);
		return (1);
	}
	pid = atoi(argv[1]);
	i = 0;
	while (i < argc - 2)
	{
		send_morse(pid, argv[2 + i]);
		i++;
	}
	return (0);
}
