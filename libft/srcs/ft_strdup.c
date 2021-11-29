/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:11:42 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/22 16:11:42 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	src_len;

	src_len = ft_strlen((char *)s1);
	dup = malloc(sizeof(char) * (src_len + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, src_len + 1);
	return (dup);
}
