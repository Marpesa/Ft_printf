/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:45:05 by lmery             #+#    #+#             */
/*   Updated: 2021/12/10 16:11:20 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_check_lim(unsigned int a)
{
	if (a == 0)
	{
			write (1, "0", 1);
			return (1);
	}
	return (0);
}

static int ft_putui_rec(unsigned int b)
{
	static int	ret = 0;

	if (b > 9)
	{
		ft_putui_rec(b / 10);
		ft_putui_rec(b % 10);
	}
	if (b <= 9)
	{
		ft_putchar(b + '0');
		ret++;
	}
	return (ret);
}

int	ft_putui(unsigned int a)
{
	int	ret;
	unsigned int	b;

	b = a;
	if (ft_check_lim(a))
			return (1);
	ret = ft_putui_rec(b);
	if ((unsigned int)a > INT_MAX)
			return (10);
	return (ret);
}
