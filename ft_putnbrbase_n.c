/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:22:43 by lmery             #+#    #+#             */
/*   Updated: 2021/12/17 16:53:12 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf.h"

static int	ft_convert(long int nbr, char *base, int l, int *res)
{
	if (nbr >= l)
	{
		(*res) += 1;
		ft_convert((nbr / l), base, l, res);
		ft_putchar(base[nbr % l]);
	}
	else
	{	
		ft_putchar(base[nbr % l]);
		(*res) += 1;
	}
	return (*res);
}

int	ft_putnbrbase_n(int nbr)
{
	int			l;
	long int	nb;
	int			res;
	char		*base;

	base = "0123456789";
	res = 0;
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		res++;
		nb = nb * (-1);
	}
	l = 10;
	res += ft_convert(nb, base, l, &res);
	return (res / 2);
}
