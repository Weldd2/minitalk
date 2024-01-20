/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:55:12 by amura             #+#    #+#             */
/*   Updated: 2024/01/21 00:34:36 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_stream {
	int		pid;
	int		bit_index;
	int		char_index;
	char	*received_bit;
	char	*message;
} t_stream;

t_stream	*find_stream_in_list(t_list *stream, int pid)
{
	t_list	*current;

	current = stream;
	while (current)
	{
		if (((t_stream *) current->content)->pid == pid)
			return ((t_stream *)current->content);
		current = current->next;
	}
	return (NULL);
}

void	add_stream_to_list(t_stream **stream, t_list **stream_list, int pid)
{
	t_list	*node;

	*stream = malloc(sizeof(t_stream));
	(*stream)->message = malloc(MAX_MESSAGE_LENGTH * sizeof(char));
	if (!(*stream)->message)
		ft_printf("erreur");
	(*stream)->received_bit = malloc(sizeof(char) * 8);
	(*stream)->received_bit[8] = '\0';
	if (!(*stream)->received_bit)
		ft_printf("erreur");
	(*stream)->pid = pid;
	(*stream)->bit_index = 0;
	(*stream)->char_index = 0;
	node = ft_lstnew((*stream));
	ft_lstadd_back(stream_list, node);
}

void	free_stream(void *stream)
{
	free(((t_stream *)stream)->message);
	free(((t_stream *)stream)->received_bit);
}

void remove_stream_from_list(t_list **stream_list, int pid, void (*free_func)(void *))
{
	t_list *current = *stream_list;
	t_list *previous = NULL;

	while (current != NULL)
	{
		t_stream *current_stream = (t_stream *)current->content;
		if (current_stream->pid == pid)
		{
			if (previous == NULL)
				*stream_list = current->next;
			else
				previous->next = current->next;
			free_func(current->content);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

void	handler(int sig, siginfo_t *info, __attribute__((unused)) void *context)
{
	static t_list	*stream_list = NULL;
	t_stream 		*stream;
	char			signal;

	if (sig == SIGUSR1)
		signal = '0';
	else if (sig == SIGUSR2)
		signal = '1';
	else
		return ;
	stream = find_stream_in_list(stream_list, info->si_pid);
	if (!stream)
	{
		add_stream_to_list(&stream, &stream_list, info->si_pid);
		stream = find_stream_in_list(stream_list, info->si_pid);
	}
	if (stream->bit_index < 8)
	{
		stream->received_bit[stream->bit_index] = signal;
		stream->bit_index++;
	}
	if (stream->bit_index == 8)
	{
		stream->received_bit[stream->bit_index] = '\0';
		stream->message[stream->char_index] = ft_bin_to_int(stream->received_bit);
		stream->bit_index = 0;
		if (stream->message[stream->char_index] == '\0')
		{
			ft_printf("From %d : %s\n", stream->pid, stream->message);
			remove_stream_from_list(&stream_list, stream->pid, &free_stream);
		}
		else 
			stream->char_index++;
	}
}

int main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) {
		perror("sigaction");
		return (1);
	}

	ft_printf("PID: %d\n", getpid());

	while (1) {
		pause();
	}
	return (0);
}

