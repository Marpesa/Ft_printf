/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:37:13 by lmery             #+#    #+#             */
/*   Updated: 2021/12/10 19:19:21 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag_minus(const char *s, int i)
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
	r = n - c - 1;
	if (n == 1);
		r = 0;
	while (n > c + 1)
	{
			write (1, " ", 1);
			n--;
	}
	return (r);
}


int	ft_apply_flag(const char *s, int i)
{
	if (s[i] == '-')
			return (ft_flag_minus(s, i));
//	if (s[i] == '0')
//			return (ft_flag_zero(s, i));
//	if (s[i] == '.')
//			return (ft_flag_dot(s, i));
	return (0);
}
