/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:07:48 by lmery             #+#    #+#             */
/*   Updated: 2021/12/10 14:18:12 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>

static int	ft_parse(const char *s, va_list toprint, int i, int l)
{
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i++]);
		if (s[i] == '%')
		{
			i++;
			l--;
			while (ft_flag(s[i]) != 0)
			{
				l -= 1;
				i++;
			}
			l += ft_type(s[i++], toprint);
		}
	}
	l += i - 2;
	return (l);
}

int	ft_printf(const char *s, ...)
{
	va_list	toprint;
	int		i;
	int		l;

	va_start (toprint, s);
	i = 0;
	l = 0;
	l = ft_parse(s, toprint, i, l);
	va_end (toprint);
	return (l);
}

int	main(void)
{
	int	a;
	char	b[] = "today ?";

	a = 42;
	printf("%d\n", ft_printf("Hello %p, how you doin %s\n", &a, b));
	printf("%d\n", printf("Hello %p, how you doin %s\n", &a, b));
	return (0);
}
