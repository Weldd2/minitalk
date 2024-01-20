/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:46:38 by amura             #+#    #+#             */
/*   Updated: 2023/12/10 19:03:34 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digit(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		size;
	long	n_cpy;

	n_cpy = (long)n;
	size = count_digit(n) + (n < 0);
	r = (char *)malloc(sizeof(char) * (size + 1));
	if (!r)
		return (NULL);
	r[0] = '-';
	if (n == 0)
		r[0] = '0';
	n_cpy = (long)n;
	if (n_cpy < 0)
		n_cpy = -n_cpy;
	while (size - (n < 0) > 0)
	{
		r[size - 1] = (n_cpy % 10) + '0';
		n_cpy /= 10;
		size--;
	}
	r[count_digit(n) + (n < 0)] = '\0';
	return (r);
}
