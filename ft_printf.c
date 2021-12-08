/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:07:48 by lmery             #+#    #+#             */
/*   Updated: 2021/12/08 18:52:48 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>

int ft_printf(const char *echo, ...)
{
	va_list	toprint;
	int		i;
	int		l;
	const char	*s;

	s = ft_strdup((const char *)echo);
	va_start (toprint, echo);
	i = 0;
	l = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			i++;
			l++;
		}
		if (s[i] == '%')
		{
			i++;
			l += ft_type(s[i], toprint);
			i++;
		}
	}
	va_end (toprint);
	free((char *)s);
	return (l);
}

#include <stdio.h>

int	main(void)
{
	int	a;
	char	b[] = "today ?";

	a = NULL;
	ft_printf("%d\n", ft_printf("%p", NULL));
	ft_printf("Hello %p, how you doin %s\n", NULL, b);
	printf("Hello %p, how you doin %s", NULL, b);
	return (0);
}
