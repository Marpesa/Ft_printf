/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:07:48 by lmery             #+#    #+#             */
/*   Updated: 2021/12/14 17:46:07 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(const char *s, va_list toprint, int i, int l)
{
	int		f;
	va_list temp;

	va_copy(temp, toprint);
	f = 0;
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i++]);
		if (s[i] == '%')
		{
			i++;
			l--;
			f = ft_flag(s, i);
			if (f > 0)
			{
				l -= f;
				i += f;
			}
			if (f < 0)
			{
				l += f;
				i -= f;
				l += ft_apply_flag(s, (i + f), temp);
			}
			l += ft_type(s[i++], toprint) - 1;
			if (f > 0)
				l += ft_apply_flag(s, (i - f - 1), temp);
		}
	}
	l += i;
	return (l);
}

int	ft_printf(const char *echo, ...)
{
	va_list	toprint;
	int		i;
	int		l;
	const char *s;

	s = ft_strdup(echo);
	if (!s)
			return (0);
	va_start (toprint, echo);
	i = 0;
	l = 0;
	l = ft_parse(s, toprint, i, l);
	free((char *)s);
	va_end (toprint);
	return (l);
}


int	main(void)
{
	int	a;
	char	b[] = "centimes";

	a = 42684;
	printf("%d\n", ft_printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("%d\n", printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	return (0);
}
