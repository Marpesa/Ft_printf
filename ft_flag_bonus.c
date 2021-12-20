/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:55:48 by lmery             #+#    #+#             */
/*   Updated: 2021/12/17 18:06:07 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag(const char *s, int i)
{
	int	r;

	r = 0;
	while ((s[i] >= '1' && s[i] <= '9')
		|| ((s[i] == '0') && (s[i + 1] >= '0' && s[i + 1] <= '9')))
	{
		r--;
		i++;
	}
	if (r < 0 && (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd'
			|| s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X'))
		return (r);
	if (s[i] == '-' || s[i] == '0' || s[i] == '.')
	{
		i++;
		r++;
		while ((s[i] >= '0' && s[i] <= '9') || (s[i -1] == '0' && s[i] == '-'))
		{
			i++;
			r++;
		}
	}
	return (r);
}