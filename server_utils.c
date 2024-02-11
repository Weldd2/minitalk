/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:51:35 by antoinemura       #+#    #+#             */
/*   Updated: 2024/02/11 01:51:50 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stream	*find_stream_in_list(t_list *stream, int pid)
{
	t_list	*current;

	current = stream;
	while (current)
	{
		if (((t_stream *) current->content)->pid == pid)
			return (((t_stream *)current->content));
		current = current->next;
	}
	return ((NULL));
}

void	add_stream_to_list(t_stream **stream, t_list **stream_list, int pid)
{
	t_list	*node;

	*stream = malloc(sizeof(t_stream));
	(*stream)->message = malloc(MAX_MESSAGE_LENGTH * sizeof(char));
	if (!(*stream)->message)
		ft_printf("erreur");
	ft_memset((*stream)->message, '\0', MAX_MESSAGE_LENGTH);
	(*stream)->received_bit[8] = '\0';
	(*stream)->pid = pid;
	(*stream)->bit_index = 0;
	(*stream)->char_index = 0;
	node = ft_lstnew((*stream));
	ft_lstadd_back(stream_list, node);
}

void	free_stream(void *stream)
{
	free(((t_stream *)stream)->message);
	free(stream);
}

void	remove_stream_from_list(t_list **stream_list, int pid,
								void (*free_func)(void *))
{
	t_list		*current;
	t_list		*previous;
	t_stream	*current_stream;

	current = *stream_list;
	previous = NULL;
	while (current != NULL)
	{
		current_stream = (t_stream *)current->content;
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

char	interpret_signal(int sig)
{
	if (sig == SIGUSR1)
		return ('0');
	else if (sig == SIGUSR2)
		return ('1');
	return ('\0');
}
