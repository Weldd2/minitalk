/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:36:22 by marvin            #+#    #+#             */
/*   Updated: 2023/10/13 16:36:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char		*s_cpy;
	size_t			compteur;

	s_cpy = s;
	compteur = 0;
	while (*s_cpy)
	{
		compteur++;
		s_cpy++;
	}
	return (compteur);
}
