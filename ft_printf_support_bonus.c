/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_support_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:55:57 by kalshaer          #+#    #+#             */
/*   Updated: 2022/09/01 15:05:54 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_countdigit(int d)
{
	int r;
	char *t;

	t = ft_itoa(d);
	r = ft_strlen(t);
	free (t);
	return (r);
}

void	ft_printf_putusnbr(unsigned int u, int *i)
{
	if (u > 9)
	{
		*i = *i + 1;
		ft_printf_putusnbr(u / 10, i);
	}
	u = (u % 10) + 48;
	write(1, &u, 1);
}

void	ft_printf_printp(size_t p, int *i, char *base)
{
	if (p >= 16)
	{
		*i = *i + 1;
		ft_printf_printp(p / 16, i, "0123456789abcdef");
	}
	write(1, &base[p % 16], 1);
}

void	ft_printf_printx(unsigned int x, int *i, char *base)
{
	if (x >= 16)
	{
		*i = *i + 1;
		ft_printf_printx(x / 16, i, "0123456789abcdef");
	}
	write(1, &base[x % 16], 1);
}

void	ft_printf_printX(unsigned int X, int *i, char *base)
{
	if (X >= 16)
	{
		*i = *i + 1;
		ft_printf_printX(X / 16, i, "0123456789ABCDEF");
	}
	write(1, &base[X % 16], 1);
}