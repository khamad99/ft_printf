/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:31:28 by kalshaer          #+#    #+#             */
/*   Updated: 2022/08/21 17:11:23 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static void to_in(s_type *r)
{
	r->c = 0;
	r->s = 0;
	r->p = 0;
	r->d = 0;
	r->i = 0;
	r->u = 0;
}

// static int to_convert(va_list r, char s, s_type *t)
// {
// 	if (s == 'c')
// 	{
// 		t->c = va_arg (r, int);
// 		write (1, &t->c, 1);
// 	}
// 	return (2);
// }

int	ft_printf(const char *s, ...)
{
	int i;
	va_list r;
	s_type ss;
	s_type *t = &ss;

	to_in (t);
	va_start (r, s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			write (1, &s[i], 1);
		if (s[i] == '%' && s[i + 1] == 'c')
		{
			t->c = va_arg (r, int);
			ft_putchar_fd(t->c, 1);
			i++;
		}
		if (s[i] == '%' && s[i + 1] == 's')
		{
			t->s = va_arg (r, char *);
			ft_putstr_fd(t->s, 1);
			i++;
		}
		// if (s[i] == '%' && s[i + 1] == 'p')
		// {
		// 	t->p = va_arg (r, void *);
		// 	ft_putstr_fd(t->s, 1);
		// 	i++;
		// }
		if (s[i] == '%' && s[i + 1] == 'd')
		{
			t->d = va_arg (r, int);
			ft_putnbr_fd(t->d, 1);
			i++;
		}
		if (s[i] == '%' && s[i + 1] == 'i')
		{
			t->i = va_arg (r, int);
			ft_putnbr_fd(t->i, 1);
			i++;
		}
		if (s[i] == '%' && s[i + 1] == 'u')
		{
			t->u = va_arg (r, unsigned int);
			ft_putnbr_fd(t->u, 1);
			i++;
		}
		i++;
	}
	va_end(r);
	return (2);
}

int main (void)
{
	ft_printf("123%c456%c   1%s1234%d1011%i2222%u111\n", 'p', 'e', "khalid", 90000, 1234, 6);
	printf("123%c456%c   1%s1234%d1011%i2222%u111\n", 'p', 'e', "kahlid", 90000, 1234, 6);
}