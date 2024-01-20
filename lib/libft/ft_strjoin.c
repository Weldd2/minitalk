/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:46:02 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 23:49:35 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	s = (char *)malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		s[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}
