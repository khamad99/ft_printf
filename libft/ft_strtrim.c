/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:09:25 by kalshaer          #+#    #+#             */
/*   Updated: 2022/08/17 13:39:33 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	int		len;

	if (!s1 || !set)
		return (0);
	while (s1[0] && ft_strchr(set, s1[0]))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len - 1]))
		len--;
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (0);
	r[len] = 0;
	while (len > 0)
	{
		r[len - 1] = s1[len - 1];
		len--;
	}
	return (r);
}
