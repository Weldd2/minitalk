/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:42:50 by marvin            #+#    #+#             */
/*   Updated: 2023/10/13 19:42:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s2 && *s1 == *s2)
	{
		n--;
		if (n == 0)
			return (0);
		s1++;
		s2++;
	}
	if (n)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
