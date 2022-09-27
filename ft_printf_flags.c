/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:38:30 by kalshaer          #+#    #+#             */
/*   Updated: 2022/09/01 14:59:29 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_flags(const char *s, va_list r, s_type *t)
{
	int num;
	int	x;

	num = 1;
	if (t->hash && *(s + 1) == 'x')
	{
		x = va_arg (r, int);
		if (x != 0)
		{
			ft_putstr_fd("0x", 1);
			num = num + 2;
		}
		ft_printf_printx(x, &num, "0123456789abcdef");
		return (num);
	}
	if (t->hash && *(s + 1) == 'X')
	{
		x = va_arg (r, int);
		if (x != 0)
		{
			ft_putstr_fd("0X", 1);
			num = num + 2;
		}
		ft_printf_printX(x, &num, "0123456789ABCDEF");
		return (num);
	}
	return (ft_printf_flags2(s, r, t));
}

int	ft_printf_flags2(const char *s, va_list r, s_type *t)
{
	int num;
	int d;

	num = 0;
	if (t->space && !t->plus && *(s + 1) == 'd')
	{
		d = va_arg (r, int);
		if (d >= 0)
		{
			ft_putstr_fd(" ", 1);
			num = num + 1;
		}
		ft_putnbr_fd(d, 1);
		return (num + ft_printf_countdigit(d));
	}
	return (ft_printf_flags3(s, r, t));
}

int	ft_printf_flags3(const char *s, va_list r, s_type *t)
{
	int num;
	int i;

	num = 0;
	if (t->space && !t->plus && *(s + 1) == 'i')
	{
		i = va_arg (r, int);
		if (i >= 0)
		{
			ft_putstr_fd(" ", 1);
			num = num + 1;
		}
		ft_putnbr_fd(i, 1);
		return (num + ft_printf_countdigit(i));
	}
	return (ft_printf_flags4(s, r, t));
}

int	ft_printf_flags4(const char *s, va_list r, s_type *t)
{
	int num;
	int i;

	num = 0;
	if (t->plus && *(s + 1) == 'i')
	{
		i = va_arg (r, int);
		if (i >= 0)
		{
			ft_putstr_fd("+", 1);
			num = num + 1;
		}
		ft_putnbr_fd(i, 1);
		return (num + ft_printf_countdigit(i));
	}
	return (ft_printf_flags5(s, r, t));
}

int	ft_printf_flags5(const char *s, va_list r, s_type *t)
{
	int num;
	int d;

	num = 0;
	if (t->plus && *(s + 1) == 'd')
	{
		d = va_arg (r, int);
		if (d >= 0)
		{
			ft_putstr_fd("+", 1);
			num = num + 1;
		}
		ft_putnbr_fd(d, 1);
		return (num + ft_printf_countdigit(d));
	}
	return (ft_printf_flags6(s, r, t));
}

int	ft_printf_flags6(const char *s, va_list r, s_type *t)
{
	char	*ss;
	if (t->space && *(s + 1) == 's')
	{
		ss = va_arg (r, char *);
		if (!ss)
		{
			ft_putstr_fd("(null)", 1);
			return (ft_strlen("(null)"));
		}
		else
		{
			ft_putstr_fd(ss, 1);
			return (ft_strlen(ss));
		}
	}
	return (0);
}