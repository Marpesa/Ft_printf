/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:37:13 by lmery             #+#    #+#             */
/*   Updated: 2021/12/13 15:50:53 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag_minus(const char *s, int i, int l)
{
	int	n;
	int	r;
	int	c;

	r = 0;
	n = 0;
	c = 0;
	i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
			n += (s[i] - 48);
			if (s[i + 1] >= '0' && s[i + 1] <= '9')
					n *= 10;
			i++;
			c++;
	}
	r = n - 1;
	if (n == 1)
		r = 0;
//	printf("N = %d\n", n);
//	printf("L = %d\n", l);
	if (n > l)
	{
		while (n - l)
			{
					write (1, " ", 1);
					n--;
			}
	}
	return (r - n);
}


int	ft_apply_flag(const char *s, int i, va_list args)
{
	int	l;

	l = 0;
	l = ft_strlen(va_arg(args, char *));
	if (s[i] == '-')
			return (ft_flag_minus(s, i, l));
//	if (s[i] == '0')
//			return (ft_flag_zero(s, i));
//	if (s[i] == '.')
//			return (ft_flag_dot(s, i));

	return (0);
}
