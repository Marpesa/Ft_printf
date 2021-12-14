/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:37:13 by lmery             #+#    #+#             */
/*   Updated: 2021/12/14 17:34:39 by lmery            ###   ########.fr       */
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
	r = n;
	if (n == 1)
		r = 1;
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
	int		l;
	int		j;

	j = 0;
	l = 0;
	l = ft_strlen_arg(s, i, args);
	while((s[i + j] >= '0' && s[i + j] <= '9') 
			|| s[i + j] == '-' || s[i + j] == '.')
		j++;
	if (s[i + j] == '%')
			return (0);
	if (s[i] == '-')
			return (ft_flag_minus(s, i, l));
	if ((s[i] >= '1' && s[i] <= '9')	
			|| ((s[i] == '0') && (s[i + 1] > '0' && s[i + 1] <= '9')))
		return (ft_flag_int(s, i, l));
//	if (s[i] == '0')
//			return (ft_flag_zero(s, i));
//	if (s[i] == '.')
//			return (ft_flag_dot(s, i));

	return (0);
}
