/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:30:13 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 23:37:56 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;
	char	max;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	if (ft_strlen(s) - start > len)
		max = len;
	else
		max = ft_strlen(s) - start;
	r = malloc((max * sizeof(char)) + 1);
	if (!r)
		return (NULL);
	while (s[i + start] && i < len)
	{
		r[i] = s[i + start];
		i++;
	}
	r[i] = '\0';
	return (r);
}
