/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:10:16 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/27 00:25:42 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	last;

	i = 0;
	last = 0;
	while (src[i] != '\0')
	{
		if (i + 1 < size)
		{
			last++;
			dest[i] = src[i];
		}
		i++;
	}
	if (size > 0)
		dest[last] = '\0';
	return (i);
}
