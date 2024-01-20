/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:37:48 by antoinemura       #+#    #+#             */
/*   Updated: 2023/12/09 20:47:15 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (count);
	while (*s)
	{
		write(1, s, 1);
		count++;
		s++;
	}
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int i)
{
	int	temp;
	int	count;

	temp = 0;
	count = 0;
	if (i == -2147483648)
	{
		ft_putstring("-2147483648");
		return (11);
	}
	if (i < 0)
	{
		count += ft_putchar('-');
		i *= -1;
	}
	temp = i % 10;
	if (i >= 10)
	{
		count += ft_putnbr(i / 10);
	}
	count += ft_putchar(temp + '0');
	return (count);
}

int	ft_putunsignednbr(unsigned int i)
{
	int	temp;
	int	count;

	temp = 0;
	count = 0;
	temp = i % 10;
	if (i >= 10)
	{
		count += ft_putnbr(i / 10);
	}
	count += ft_putchar(temp + '0');
	return (count);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned int	base_len;
	int				count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
	{
		count += ft_putnbr_base(nbr / base_len, base);
		count += ft_putnbr_base(nbr % base_len, base);
	}
	else
		count += ft_putchar(base[nbr]);
	return (count);
}
