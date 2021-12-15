/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:37:13 by lmery             #+#    #+#             */
/*   Updated: 2021/12/15 20:54:43 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag_minus(const char *s, int i, int l)
{
	int	n;
	int	r;

	r = 0;
	n = 0;
	i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n += (s[i] - 48);
		if (s[i + 1] >= '0' && s[i + 1] <= '9')
				n *= 10;
		i++;
	}
	r = n;
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
	int		l;
	int		j;

	j = 0;
	l = 0;
	l = ft_strlen_arg(s, i, args);
//	printf(" L = %d\n", l);
	while((s[i + j] >= '0' && s[i + j] <= '9') 
			|| s[i + j] == '-' || s[i + j] == '.')
		j++;
	if (s[i + j] == '%')
		return (0);
	if ((s[i] == '-') || (s[i] == '0' && s[i + 1] == '-'))
	{
		if (s[i] == '0')
				i++;
		return (ft_flag_minus(s, i, l));
	}
	if ((s[i] >= '1' && s[i] <= '9'))	
		return (ft_flag_int(s, i, l));
	if (s[i] == '0')
			return (ft_flag_zero(s, i, l));
//	if (s[i] == '.')
//			return (ft_flag_dot(s, i));
	return (0);
}
