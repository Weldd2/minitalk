/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:39:33 by antoinemura       #+#    #+#             */
/*   Updated: 2024/02/11 03:15:39 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*char_to_binary(char c)
{
	int	i;
	int	*b;

	b = malloc(sizeof(int) * 8);
	i = 0;
	while (i < 8)
	{
		if ((c << i) & 0x80)
			b[i] = 1;
		else
			b[i] = 0;
		i++;
	}
	return (b);
}

void	send_char(pid_t pid, int *bin)
{
	int	j;
	int	signal;

	j = 0;
	while (j < 8)
	{
		signal = SIGUSR1;
		if (bin[j])
			signal = SIGUSR2;
		kill(pid, signal);
		usleep(150);
		j++;
	}
	free(bin);
}

void	send_signals(pid_t pid, char *s)
{
	int	i;
	int	*bin;

	i = 0;
	while (s[i] != '\0')
	{
		bin = char_to_binary(s[i]);
		if (bin == NULL)
			return ;
		send_char(pid, bin);
		i++;
	}
	bin = char_to_binary('\0');
	if (bin == NULL)
		return ;
	send_char(pid, bin);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc < 3)
	{
		ft_printf("Usage: %s <pid> <string>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (i < argc - 2)
	{
		send_signals(pid, argv[2 + i]);
		i++;
	}
	return (0);
}
