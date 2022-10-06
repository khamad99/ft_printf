/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:34:05 by kalshaer          #+#    #+#             */
/*   Updated: 2022/10/05 14:41:36 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_printf(const char *s, ...);
int		ft_printf_countdigit(int d);
int		ft_printf_to_convertc(char s, va_list r);
int		ft_printf_to_converts(char s, va_list r);
int		ft_printf_to_convertp(char s, va_list r);
int		ft_printf_to_convertdi(char s, va_list r);
int		ft_printf_to_convertuxxx(char s, va_list r);
void	ft_printf_putusnbr(unsigned int u, int *i);
void	ft_printf_printp(size_t p, int *i, char *base);
void	ft_printf_printx(unsigned int x, int *i, char *base);
void	ft_printf_printxx(unsigned int xx, int *i, char *base);

#endif