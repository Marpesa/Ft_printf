/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:26:43 by lmery             #+#    #+#             */
/*   Updated: 2021/12/17 16:36:23 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
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

static int	ft_convert(unsigned long int nbr, char *base, size_t l, int *ret)
{
	if (nbr >= l)
	{	
		(*ret) += 1;
		ft_convert((nbr / l), base, l, ret);
		ft_putchar(base[nbr % l]);
	}
	else
	{	
		ft_putchar(base[nbr % l]);
		(*ret) += 1;
	}
	return (*ret);
}

int	ft_ub(unsigned long int nbr, char *base)
{
	size_t				l;
	unsigned long int	nb;
	int					ret;

	ret = 0;
	nb = nbr;
	if (!nbr)
	{
		write(1, "(nil)", 5);
		return (3);
	}
	if (!ft_error(base))
		return (0);
	write(1, "0x", 2);
	l = ft_strlen(base);
	ft_convert(nb, base, l, &ret);
	return (ret);
}
