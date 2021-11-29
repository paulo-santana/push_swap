/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 00:04:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/20 00:04:25 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem1;
	unsigned char	*mem2;
	size_t			i;

	mem1 = (unsigned char *) s1;
	mem2 = (unsigned char *) s2;
	i = -1;
	while (++i < n)
		if (mem1[i] != mem2[i])
			return (mem1[i] - mem2[i]);
	return (0);
}
