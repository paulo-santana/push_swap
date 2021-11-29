/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:50:24 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/27 00:23:13 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char				*c_pos;
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	c_pos = ft_memchr(src, c, n);
	i = 0;
	s = src;
	d = dest;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			break ;
		i++;
	}
	if (c_pos)
		return (dest + i + 1);
	return (NULL);
}
