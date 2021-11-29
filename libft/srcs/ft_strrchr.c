/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:33:58 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/14 16:27:01 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_pos;

	i = 0;
	last_pos = NULL;
	while (1)
	{
		if (s[i] == (unsigned char)c)
			last_pos = (char *)s + i;
		if (!s[i])
			return (last_pos);
		i++;
	}
}
