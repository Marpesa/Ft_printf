/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:22:43 by lmery             #+#    #+#             */
/*   Updated: 2021/12/10 14:34:04 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf.h"

static int	ft_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1 || !(base))
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if ((base[i] == '+') || (base[i] == '-')
			|| (base[i] <= 32) || (base [i] == 127))
			return (0);
		i++;
	}
	return (1);
}

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

int	ft_putnbrbase_n(int nbr, char *base)
{
	int			l;
	long int	nb;
	int			res;

	res = 0;
	nb = nbr;
	if (!ft_error(base))
		return (0);
	if (nb < 0)
	{
		ft_putchar('-');
		res++;
		nb = nb * (-1);
	}
	l = ft_strlen(base);
	res += ft_convert(nb, base, l, &res);
	return (res / 2);
}
