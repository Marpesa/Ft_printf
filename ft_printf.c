/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:07:48 by lmery             #+#    #+#             */
/*   Updated: 2021/12/13 15:51:58 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(const char *s, va_list toprint, int i, int l)
{
	int	f;
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
			if (ft_flag(s, i) != 0)
			{
				f = ft_flag(s, i);
				l -= f;
				i += f;
			}
			l += ft_type(s[i++], toprint) - 1;
			if (f != 0)
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
	char	b[] = "today ?";

	a = 42;
	printf("%d\n", ft_printf("%c ", '0'));
	printf("%d\n", printf("%c ", '0'));
	return (0);
}
