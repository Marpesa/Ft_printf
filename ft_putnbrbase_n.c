/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:22:43 by lmery             #+#    #+#             */
/*   Updated: 2021/12/08 17:33:13 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

static int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

static int	ft_convert(long int nbr, char *base, int L)
{
	int	ret;

	ret = 0;
	if (nbr >= L)
	{	
		ft_convert((nbr / L), base, L);
		ft_putchar(base[nbr % L]);
		ret++;
	}
	else
	{	
		ft_putchar(base[nbr % L]);
		ret++;
	}
	return (ret);
}

int	ft_putnbrbase_n(int nbr, char *base)
{
	int			L;
	long int	nb;
	int			ret;

	ret = 0;
	nb = nbr;
	if (!ft_error(base))
		return (0);
	if (nb < 0)
	{
		ft_putchar('-');
		ret++;
		nb = nb * (-1);
	}
	L = ft_strlen(base);
	ret += ft_convert(nb, base, L);
	return (ret);
}
