/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:34:05 by kalshaer          #+#    #+#             */
/*   Updated: 2022/09/04 17:03:06 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef struct t_type
{
	int	space;
	int	hash;
	int	plus;
	int	check;
	int	snum;
	int	zero;
	int	dash;
	int	width;
	int	dot;
}	s_type;


int	ft_printf(const char *, ...);
int	ft_printf_countdigit(int d);
const char	*ft_printf_removeextraflags(const char *s, s_type *t);
int	ft_printf_checkflags(s_type *t);
int	ft_printf_to_convertc(const char *s, va_list r, s_type *t);
int	ft_printf_to_converts(const char *s, va_list r, s_type *t);
int	ft_printf_to_convertp(const char *s, va_list r, s_type *t);
int	ft_printf_to_convertdi(const char *s, va_list r, s_type *t);
int	ft_printf_to_convertuxX(const char *s, va_list r, s_type *t);
int	ft_printf_flags(const char *s, va_list r, s_type *t);
int	ft_printf_flags2(const char *s, va_list r, s_type *t);
int	ft_printf_flags3(const char *s, va_list r, s_type *t);
int	ft_printf_flags4(const char *s, va_list r, s_type *t);
int	ft_printf_flags5(const char *s, va_list r, s_type *t);
int	ft_printf_flags6(const char *s, va_list r, s_type *t);
void	ft_printf_putusnbr(unsigned int u, int *i);
void	ft_printf_printp(size_t p, int *i, char *base);
void	ft_printf_printx(unsigned int x, int *i, char *base);
void	ft_printf_printX(unsigned int X, int *i, char *base);

#endif