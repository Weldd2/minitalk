/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:38:37 by antoinemura       #+#    #+#             */
/*   Updated: 2023/12/09 20:30:27 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_d_i(va_list *ap)
{
	int	d;

	d = va_arg(*ap, int);
	return (ft_putnbr(d));
}

int	ft_handle_u(va_list *ap)
{
	unsigned int	u;

	u = va_arg(*ap, unsigned int);
	return (ft_putunsignednbr(u));
}

int	ft_handle_c(va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	return (ft_putchar(c));
}

int	ft_handle_s(va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
		return (ft_putstring("(null)"));
	return (ft_putstring(s));
}

int	ft_handle_p(va_list *ap)
{
	void	*p;

	p = va_arg(*ap, void *);
	if (p == NULL)
		return (ft_putstring("0x0"));
	return (ft_printaddr(p));
}
