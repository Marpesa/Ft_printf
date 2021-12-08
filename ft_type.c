/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:30:40 by lmery             #+#    #+#             */
/*   Updated: 2021/12/08 18:40:53 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_type(char c, va_list args)
{
	int	r;

	if (c == 'c')
		r = ft_putchar_n(va_arg(args, int));
	if (c == 's')
		r = ft_putstr_n(va_arg(args, char *));
	if (c == 'p')
	{	
		write(1, "0x", 2);
		r = ft_ub(va_arg(args, unsigned long int), "0123456789abcdef") + 2;
	}
	if (c == 'd' || c == 'i')
		r = ft_putnbrbase_n(va_arg(args, int), "0123456789");
	if (c == 'u')
		r = ft_putui(va_arg(args, unsigned long int));
	if (c == 'x')
		r = ft_putnbrbase_n(va_arg(args, int), "0123456789abcdef");
	if (c == 'X')
		r = ft_putnbrbase_n(va_arg(args, int), "0123456789ABCDEF");
	if (c == '%')
		r = ft_putchar_n('%');
	return (r);
}
