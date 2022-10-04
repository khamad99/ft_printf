/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:31:28 by kalshaer          #+#    #+#             */
/*   Updated: 2022/10/04 12:16:11 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_printf_s_type(s_type * t)
{
	t->check = 0;
	t->hash = 0;
	t->plus = 0;
	t->space = 0;
}

const char	*ft_printf_removeextraflags(const char *s, s_type *t)
{
	int	i;
	int	ii;

	i = 1;
	ii = 2;
	while ((s[i] == '#' || s[i] == '+') && ft_strchr("# +", s[ii]))
		ii++;
	while (s[i] == ' ' && ft_strchr("# +", s[ii]))
	{
		t->hash = 1;
		if (s[ii] == '+')
		{
			t->space = 0;
			t->plus = 1;
		}
		ii++;
	}
	if (t->plus || t->hash || t->space)
	{
		t->check = ii;
		return (&s[ii - 1]);
	}
	return (s);
}

const char	*ft_printf_checkflags(const char *s, s_type *t)
{
	if (s[1] == '#')
		t->hash = 1;
	if (s[1] == ' ')
		t->space = 1;
	if (s[1] == '+')
		t->plus = 1;
	return (ft_printf_removeextraflags(s, t));
}

int	ft_printf_checkspases(s_type *t)
{
	if (t->check)
		return (t->check);
	else
		return (0);
}

int	ft_printf_tomin(const char *s, va_list r, s_type t)
{
	int		i;
	int		num;

	num = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != '%')
		{
			write (1, &s[i], 1);
			num++;
		}
		if (s[i] == '%' && (ft_strchr("cspdiuxX%# +", s[i + 1])))
		{
			if (ft_strchr("# +", s[i + 1]))
			{
				num = num + ft_printf_to_convertc (ft_printf_checkflags (&s[i], &t), r, &t);
				i = i + ft_printf_checkspases(&t);
				ft_printf_s_type(&t);
			}
			else
			{
				num = num + ft_printf_to_convertc (&s[i + 1], r, &t);
				i++;
			}
		}
	}
	return (num);
}

int	ft_printf(const char *s, ...)
{
	va_list	r;
	s_type	t;
	int		num;

	ft_printf_s_type(&t);
	va_start (r, s);
	num = ft_printf_tomin(s, r, t);
	va_end(r);
	return (num);
}
