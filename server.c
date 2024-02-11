/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:39:51 by antoinemura       #+#    #+#             */
/*   Updated: 2024/02/11 01:58:37 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stream	*manage_stream(t_list **stream_list, int pid, char signal)
{
	t_stream	*stream;

	stream = find_stream_in_list(*stream_list, pid);
	if (!stream)
	{
		add_stream_to_list(&stream, stream_list, pid);
		stream = find_stream_in_list(*stream_list, pid);
	}
	if (stream->bit_index < 8)
	{
		stream->received_bit[stream->bit_index] = signal;
		stream->bit_index++;
	}
	return (stream);
}

void	process_received_bits(t_stream *stream, t_list **stream_list)
{
	char	*r;

	if (stream->bit_index == 8)
	{
		stream->received_bit[stream->bit_index] = '\0';
		r = stream->received_bit;
		stream->message[stream->char_index] = ft_bin_to_int(r);
		stream->bit_index = 0;
		if (stream->message[stream->char_index] == '\0')
		{
			ft_printf("From %d : %s\n", stream->pid, stream->message);
			remove_stream_from_list(stream_list, stream->pid, &free_stream);
		}
		else
			stream->char_index++;
	}
}

void	handler(int sig, siginfo_t *info, __attribute__((unused))void *context)
{
	static t_list	*stream_list = NULL;
	char			signal;
	t_stream		*stream;

	if (info->si_pid == 0)
	{
		ft_printf("PID = 0, signal = %d\n", sig);
		return ;
	}
	signal = interpret_signal(sig);
	if (signal == '\0')
		return ;
	stream = manage_stream(&stream_list, info->si_pid, signal);
	process_received_bits(stream, &stream_list);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		return ((1));
	}
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return ((0));
}
