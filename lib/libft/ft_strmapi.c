/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:21:03 by marvin            #+#    #+#             */
/*   Updated: 2023/11/05 15:31:55 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;
	int		c;

	if (s == NULL || f == NULL)
		return (NULL);
	c = 0;
	r = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!r)
		return (NULL);
	while (s[c])
	{
		r[c] = f(c, s[c]);
		c++;
	}
	r[c] = '\0';
	return (r);
}
