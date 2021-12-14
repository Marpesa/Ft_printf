/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:30:40 by lmery             #+#    #+#             */
/*   Updated: 2021/12/14 17:30:29 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_type(char c, va_list args)
{
	int	r;

	r = 0;
	if (c == 'c')
		r = ft_putchar_n(va_arg(args, int));
	else if (c == 's')
		r = ft_putstr_n(va_arg(args, char *));
	else if (c == 'p')
		r = ft_ub(va_arg(args, unsigned long int), "0123456789abcdef") + 2;
	else if (c == 'd' || c == 'i')
		r = ft_putnbrbase_n(va_arg(args, int), "0123456789");
	else if (c == 'u')
		r = ft_putui(va_arg(args, unsigned int));
	else if (c == 'x')
		r = ft_putx(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		r = ft_putx(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		r = ft_putchar_n('%');
	return (r);
}
