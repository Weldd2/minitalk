/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:22:22 by amura             #+#    #+#             */
/*   Updated: 2024/02/11 01:57:30 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include "lib/libft/libft.h"
# include "lib/printf/ft_printf.h"
# include "lib/hash_table/hash_table.h"

# define MAX_MESSAGE_LENGTH 10240

typedef struct s_stream
{
	int		pid;
	int		bit_index;
	int		char_index;
	char	received_bit[9];
	char	*message;
}	t_stream;

void		free_stream(void *stream);
void		remove_stream_from_list(t_list **stream_list, int pid,
				void (*free_func)(void *));
void		add_stream_to_list(t_stream **stream, t_list **stream_list, int pid)
			;
t_stream	*find_stream_in_list(t_list *stream, int pid);
char		interpret_signal(int sig);

#endif