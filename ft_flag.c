/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:55:48 by lmery             #+#    #+#             */
/*   Updated: 2021/12/10 19:04:04 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag(const char *s, int i)
{
	int	r;

	r = 0;
	if (s[i] == '-' || s[i] == '0' || s[i] == '.')
	{
			i++;
			r++;
			while (s[i] >= '0' && s[i] <= '9')
			{
					i++;
					r++;
			}
	}
	return (r);
}
