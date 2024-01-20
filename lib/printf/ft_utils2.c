/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:26:09 by antoinemura       #+#    #+#             */
/*   Updated: 2023/12/09 20:31:39 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_2(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	int				count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= base_len)
	{
		count += ft_putnbr_base_2(nbr / base_len, base);
		count += ft_putnbr_base_2(nbr % base_len, base);
	}
	else
		count += ft_putchar(base[nbr]);
	return (count);
}

int	ft_printaddr(void *addr)
{
	ft_putchar('0');
	ft_putchar('x');
	return (2 + ft_putnbr_base((long)addr, "0123456789abcdef"));
}

int	ft_handle_x(va_list *ap)
{
	int	s;

	s = va_arg(*ap, int);
	return (ft_putnbr_base_2(s, "0123456789abcdef"));
}
