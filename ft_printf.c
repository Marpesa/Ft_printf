/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:07:48 by lmery             #+#    #+#             */
/*   Updated: 2021/12/13 18:43:32 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(const char *s, va_list toprint, int i, int l)
{
	int		f;
//	int		t;
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
	//		printf ("F = %d\n", f);
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
	char	b[] = "today ?";

	a = 42;
//	printf("%d\n", ft_printf("%12c", 'a'));
	printf("%d\n", printf("%12c", 'a'));
	return (0);
}

// Modifier le strlen : coupler a un itoa, et parametre de type void afin de 
// faire une fonction qui calcul la taille de l'argument avant de l'ecrire.
