/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:22:22 by amura             #+#    #+#             */
/*   Updated: 2024/01/21 17:18:27 by antoinemura      ###   ########.fr       */
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

#endif