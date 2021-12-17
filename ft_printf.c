/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:07:48 by lmery             #+#    #+#             */
/*   Updated: 2021/12/17 19:22:16 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fpos(int *i, int *l, int *f)
{
	*l -= *f;
	*i += *f;
}

static int	ft_fneg(int *i, int l, int *f)
{
	l += *f;
	*i -= *f;
	return (l);
}

static int	ft_parse(const char *s, va_list toprint, int i, int l)
{
	int		f;
	va_list	temp;

	va_copy(temp, toprint);
	f = 0;
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i++]);
		if (s[i] == '%')
		{
			i++;
			f = ft_flag(s, i);
			if (f > 0)
				ft_fpos(&i, &l, &f);
			if (f < 0)
				l += ft_apply_flag(s, i, temp) + ft_fneg(&i, l, &f);
			l += ft_type(s[i++], toprint) - 2;
			if (f > 0)
				l += ft_apply_flag(s, (i - f - 1), temp);
		}
	}
	l += i;
	return (l);
}

int	ft_printf(const char *echo, ...)
{
	va_list		toprint;
	int			i;
	int			l;
	const char	*s;

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
/*
int	main(void)
{
	int	a;
	char	b[] = "centimes";

	a = INT_MIN;
	printf("%d\n", ft_printf(" yo %-023d\n", a));
	printf("%d\n", printf(" yo %-023d\n", a));
	return (0);
}*/
