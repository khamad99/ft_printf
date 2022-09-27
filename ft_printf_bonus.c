/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:31:28 by kalshaer          #+#    #+#             */
/*   Updated: 2022/09/04 17:16:18 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_printf_s_type(s_type * t)
{
	t->check = 0;
	t->hash = 0;
	t->plus = 0;
	t->space = 0;
	t->dot = 0;
	t->dash = 0;
	t->width = 0;
	t->zero = 0;

}

const char	*ft_printf_removeextraflags(const char *s, s_type *t)
{
	int	i;
	int	ii;

	i = 1;
	ii = 2;
	if (s[i] == '#')
	{
		t->check = 1;
		t->hash = 1;
	}
	if (s[i] == ' ')
	{
		t->check = 1;
		t->space = 1;
	}
	if (s[i] == '+')
	{
		t->check = 1;
		t->plus = 1;
	}
	while (s[i] == '#' && ft_strchr("# +", s[ii]))
	{
		t->check = 1;
		t->hash = 1;
		ii++;
	}
	while (s[i] == ' ' && !ft_strchr("cspdiuxX%", s[ii]))
	{
		t->check = 1;
		t->hash = 1;
		t->space = 1;
		if (s[ii] == '+')
		{
			t->space = 0;
			t->plus = 1;
		}
		ii++;
	}
	while ((s[i] == ' ' && ft_isdigit(s[ii])) || ft_isdigit(s[ii]))
	{
		t->check = 1;
		t->width = ft_atoi(s);
		ii++;
	}
	while (s[i] == '+' && ft_strchr("# +", s[ii]))
	{
		t->check = 1;
		t->plus = 1;
		ii++;
	}
	if (t->check)
	{
		t->check = ii;
		return (&s[ii - 1]);
	}
	return (s);
}

int	ft_printf_checkflags(s_type *t)
{
	if (t->check)
		return (t->check);
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		num;
	va_list	r;
	s_type	t;

	ft_printf_s_type(&t);
	num = 0;
	va_start (r, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] != '%')
		{
			write (1, &s[i], 1);
			num++;
		}
		if (s[i] == '%' && (ft_strchr("cspdiuxX%# +-0.", s[i + 1]) || ft_isdigit(s[i + 1])))
		{
			if (ft_strchr("# +-0.", s[i + 1]) || ft_isdigit(s[i + 1]))
			{
				num = num + ft_printf_to_convertc (ft_printf_removeextraflags (&s[i], &t), r, &t);
				i = i + ft_printf_checkflags(&t);
				ft_printf_s_type(&t);
			}
			else
			{
				num = num + ft_printf_to_convertc (&s[i + 1], r, &t);
				i++;
			}
		}
	}
	va_end(r);
	return (num);
}
