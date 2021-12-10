/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:45:05 by lmery             #+#    #+#             */
/*   Updated: 2021/12/10 13:38:30 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
#include "printf.h"

int	ft_putui(unsigned long int a)
{
	static int	ret = 0;

	if (a > 9)
	{
		ft_putui(a / 10);
		ft_putui(a % 10);
	}
	if (a <= 9)
	{
		ft_putchar(a + '0');
		ret++;
	}
	return (ret);
}
