/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:55:17 by amura             #+#    #+#             */
/*   Updated: 2023/12/17 15:22:29 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int		signe;
	int		total;

	signe = 1;
	total = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe = -signe;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		total = total * 10;
		total += (*nptr - '0');
		nptr++;
	}
	return (total * signe);
}

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
		ft_printf("Usage: %s <pid> <morse_code>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (i < argc - 2)
	{
		send_morse(pid, argv[2 + i]);
		i++;
	}
	return (0);
}
