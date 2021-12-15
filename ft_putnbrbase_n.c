/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:22:43 by lmery             #+#    #+#             */
/*   Updated: 2021/12/15 21:14:42 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf.h"

static int	ft_convert(long int nbr, int l, int *res)
{
	char base[10] = "0123456789";
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

int	ft_putnbrbase_n(int nbr, char *s, int i, int k)
{
	int			l;
	long int	nb;
	int			res;

	res = 0;
	nb = nbr;
	if (nb < 0) //&& ft_flag_zero(s, i, k
	{
		ft_putchar('-');
		res++;
		nb = nb * (-1);
	}
	l = 10;
	res += ft_convert(nb, l, &res);
	return (res / 2);
}
