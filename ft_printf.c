/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:31:28 by kalshaer          #+#    #+#             */
/*   Updated: 2022/08/31 09:00:48 by kalshaer         ###   ########.fr       */
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

// int main (void)
// {
// 	int i = 1;
// 	int r = ft_printf("%u\n", -1);
// 	int rr = printf("%u\n", -1);
// 	printf("%d\n%d\n", r, rr);
// }