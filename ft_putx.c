/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:15:32 by lmery             #+#    #+#             */
/*   Updated: 2021/12/10 16:27:40 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_putx(unsigned int nbr, char *base)
{
	int			l;
	unsigned int	nb;
	int			res;

	res = 0;
	nb = (unsigned long int) nbr;
	if (!ft_error(base))
		return (0);
	l = ft_strlen(base);
	res += ft_convert(nb, base, l, &res);
	return (res / 2);
}

