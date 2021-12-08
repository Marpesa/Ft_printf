/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:30:40 by lmery             #+#    #+#             */
/*   Updated: 2021/12/08 17:35:39 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_type(char c, va_list args)
{
	int	ret;

	if (c == 'c')
		ret = ft_putchar_n(va_arg(args, int));
	if (c == 's')
		ret = ft_putstr_n(va_arg(args, char *));
//	if (c == 'p')
//	{	
//		write(1, "0x", 2);
//		ret = ft_putnbrbase_n(*args, "0123456789abcdef");
//	}
	if (c == 'd' || c == 'i')
		ret = ft_putnbrbase_n(va_arg(args, int), "0123456789");
	if (c == 'u')
		ret = ft_putui(va_arg(args, unsigned long int));
	if (c == 'x')
		ret = ft_putnbrbase_n(va_arg(args, int), "0123456789abcdef");
	if (c == 'X')
		ret = ft_putnbrbase_n(va_arg(args, int), "0123456789ABCDEF");
	if (c == '%')
		ret = ft_putchar_n('%');
	return (ret);
}
