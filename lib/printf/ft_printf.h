/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:39:18 by antoinemura       #+#    #+#             */
/*   Updated: 2023/12/09 20:22:56 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int		ft_putchar(char c);
int		ft_putnbr(int i);
int		ft_putnbr_base_2(unsigned int nbr, char *base);
int		ft_putnbr_base(unsigned long nbr, char *base);
int		ft_printaddr(void *addr);
int		ft_putstring(char *s);
int		ft_handle_x(va_list *ap);
int		ft_handle_p(va_list *ap);
int		ft_handle_s(va_list *ap);
int		ft_handle_c(va_list *ap);
int		ft_handle_d_i(va_list *ap);
int		ft_handle_u(va_list *ap);
int		ft_handle_x_upper(va_list *ap);
int		ft_handle_percent(va_list *args);
int		ft_putunsignednbr(unsigned int i);
void	ft_initialize_handlers(int (*handlers[256])(va_list *));
int		ft_printf(const char *fmt, ...);
