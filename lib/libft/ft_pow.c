/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:22:14 by antoinemura       #+#    #+#             */
/*   Updated: 2024/01/18 14:23:46 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int nb, int exposant)
{
	int	res;

	res = 1;
	while (exposant > 0)
	{
		res = res * nb;
		exposant--;
	}
	return (res);
}
