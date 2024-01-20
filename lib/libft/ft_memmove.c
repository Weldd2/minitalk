/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:01:28 by marvin            #+#    #+#             */
/*   Updated: 2023/12/10 01:59:50 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*d;
	char	*s;

	d = dest;
	s = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (d < s)
	{
		while (n--)
			*(unsigned char *)d++ = *(unsigned char *)s++;
	}
	else
	{
		while (n--)
			*((unsigned char *)(d + n)) = *((unsigned char *)(s + n));
	}
	return (dest);
}
