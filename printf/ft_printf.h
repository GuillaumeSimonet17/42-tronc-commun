/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:24:17 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/21 15:07:13 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

unsigned long long	ft_ull_strlen(char *s);
void				ft_putchar_ret(char c, int *ret);
void				ft_putstr_ret(char *str, int *ret);
void				ft_putnbr_ret(int nb, int *ret);
void				ft_putnbr_u_ret(unsigned int nb, int *ret);
void				ft_address(unsigned long long nb, char *base, int *ret);
int					ft_if_conv(char c);
void				ft_base(int nb, char *base, int *ret);
void				ft_which_one(char c, va_list arg, int *ret);
int					ft_scan(int i, char *str, int ret, va_list arg);
int					ft_printf(const char *str, ...);

#endif