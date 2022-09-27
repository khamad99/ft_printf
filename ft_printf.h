/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:34:05 by kalshaer          #+#    #+#             */
/*   Updated: 2022/09/01 14:57:15 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "./libft/libft.h"

int	ft_printf(const char *, ...);
int	ft_printf_countdigit(int d);
int	ft_printf_to_convertc(char s, va_list r);
int	ft_printf_to_converts(char s, va_list r);
int	ft_printf_to_convertp(char s, va_list r);
int	ft_printf_to_convertdi(char s, va_list r);
int	ft_printf_to_convertuxX(char s, va_list r);
void	ft_printf_putusnbr(unsigned int u, int *i);
void	ft_printf_printp(size_t p, int *i, char *base);
void	ft_printf_printx(unsigned int x, int *i, char *base);
void	ft_printf_printX(unsigned int X, int *i, char *base);

#endif