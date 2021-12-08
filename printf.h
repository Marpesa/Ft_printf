/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:49:37 by lmery             #+#    #+#             */
/*   Updated: 2021/12/08 18:31:56 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include "Includes/libft.h"

int	ft_printf(const char *echo, ...);
void	ft_putchar(int a);
int	ft_putchar_n(int a);
int	ft_putnbrbase_n(int nbr, char *base);
int	ft_putstr_n(char *s);
int	ft_putui(unsigned long int a);
int	ft_type(char c, va_list args);
int	ft_ub(unsigned long int nbr, char *base);

char	*ft_strdup(const char *s);

#endif
