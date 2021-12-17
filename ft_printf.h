/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:49:37 by lmery             #+#    #+#             */
/*   Updated: 2021/12/17 19:27:28 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf_bonus.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *echo, ...);
void	ft_putchar(int a);
int		ft_putchar_n(int a);
int		ft_putnbrbase_n(int nbr);
int		ft_putx(unsigned int nbr, char *base);
int		ft_putstr_n(char *s);
int		ft_putui(unsigned int a);
int		ft_type(char c, va_list args);
int		ft_ub(unsigned long int nbr, char *base);
int		ft_strlen(char *str);

char	*ft_strdup(const char *s);

#endif
