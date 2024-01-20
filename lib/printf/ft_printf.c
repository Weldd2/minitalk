/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:25:40 by antoinemura       #+#    #+#             */
/*   Updated: 2023/12/15 10:18:15 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_x_upper(va_list *ap)
{
	int	s;

	s = va_arg(*ap, int);
	return (ft_putnbr_base_2(s, "0123456789ABCDEF"));
}

int	ft_handle_percent(va_list *args)
{
	(void)args;
	return (ft_putchar('%'));
}

void	ft_initialize_handlers(int (*handlers[256])(va_list *))
{
	handlers['d'] = ft_handle_d_i;
	handlers['i'] = ft_handle_d_i;
	handlers['c'] = ft_handle_c;
	handlers['s'] = ft_handle_s;
	handlers['u'] = ft_handle_u;
	handlers['p'] = ft_handle_p;
	handlers['x'] = ft_handle_x;
	handlers['X'] = ft_handle_x_upper;
	handlers['%'] = ft_handle_percent;
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		(*handlers[256])(va_list *);
	int		count;

	count = 0;
	va_start(ap, fmt);
	ft_initialize_handlers(handlers);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (handlers[(int)*fmt])
				count += handlers[(int)*fmt](&ap);
		}
		else
			count += ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (count);
}
