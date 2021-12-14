/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:03:25 by lmery             #+#    #+#             */
/*   Updated: 2021/12/14 17:44:31 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_uintlen(unsigned long int n)
{
	int	c;

	c = 0;
	if (!n)
		return (5);
	while (n != 0)
	{
			n /= 10;
			c++;
	}
	return (c);
}

static int ft_intlen(long int n)
{
	int	c;
	
	c = 0;	
//	printf("N = %d\n", n);
	if (n == LONG_MIN || n == 0)
			return (1);
	if (n == LONG_MAX)
			return (2);
	if (n == ULONG_MAX)
			return (2);
	if (!n)
		return (5);
	if (n < 0)
		c++;
	while (n != 0)
	{
			n /= 10;
			c++;
	}
	return (c);
}

static int ft_intlen_hex(unsigned long int n)
{
	int	c;

	c = 0;
	if (!n)
		return (5);
	while (n > 0)
	{
			n /= 16;
			c++;
	}
	return (c);
}

int	ft_strlen_arg(const char *s, int i, va_list args)
{
	char	c;

	while ((s[i]) && (s[i] != 'c' && s[i] != 's' && s[i] != 'p' && s[i] != 'd' 
			&& s[i] != 'i' && s[i] != 'u' && s[i] != 'x' && s[i] != 'X' 
			&& s[i] != '%'))
		i++;
	c = s[i];
	if (c == 'c' || c == '%')
		return (1);
	else if (c == 's')
		return (ft_strlen(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_intlen_hex(va_arg(args, unsigned long int)) + 2);
	else if (c == 'd' || c == 'i')
		return (ft_intlen(va_arg(args,long int)));
	else if (c == 'u')
		return (ft_uintlen(va_arg(args,unsigned long int)));
	else if (c == 'x' || c == 'X')
		return (ft_intlen_hex(va_arg(args, unsigned long int)));
	return (0);
}

	
	

	

