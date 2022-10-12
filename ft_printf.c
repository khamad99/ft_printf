/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:31:28 by kalshaer          #+#    #+#             */
/*   Updated: 2022/10/12 07:42:33 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		num;
	va_list	r;

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
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]))
		{
			num = num + ft_printf_to_convertc (s[i + 1], r);
			i++;
		}
	}
	va_end(r);
	return (num);
}
