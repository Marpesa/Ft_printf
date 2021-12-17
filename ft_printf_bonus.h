/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:01:15 by lmery             #+#    #+#             */
/*   Updated: 2021/12/17 18:02:22 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int		ft_flag(const char *s, int i);
int		ft_apply_flag(const char *s, int i, va_list args);
int		ft_flag_int(const char *s, int i, int l);
int		ft_flag_zero(const char *s, int i, int l);
int		ft_strlen_arg(const char *s, int i, va_list args);

#endif

