/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:13:21 by marvin            #+#    #+#             */
/*   Updated: 2023/10/17 14:13:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*r;
	char	*r_cpy;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	end = (char *)(s1 + ft_strlen(s1) - 1);
	while (*start && ft_strchr(set, *start))
		start++;
	while (end >= start && ft_strchr(set, *end))
		end--;
	r = (char *)malloc(1 + (end - start + 1) * sizeof(char));
	if (!r)
		return (NULL);
	r_cpy = r;
	while (start <= end)
	{
		*r = *start;
		r++;
		start++;
	}
	*r = '\0';
	return (r_cpy);
}
