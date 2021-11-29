/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:45:01 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/19 15:45:01 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = -1;
	s = (char *)src;
	d = (char *)dest;
	if (dest < src)
		while (++i < n)
			d[i] = s[i];
	else if (dest > src)
	{
		i++;
		while (i < n--)
			d[n] = s[n];
	}
	return (dest);
}
