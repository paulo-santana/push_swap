/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 02:10:18 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/23 03:05:43 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	find_start(char const *str, char const *set)
{
	size_t	start;

	start = 0;
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	return (start);
}

static size_t	find_end(char const *str, char const *set)
{
	size_t	end;

	end = ft_strlen(str);
	while (end && ft_strchr(set, str[end]))
		end--;
	return (end + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;
	char			*result;

	start = find_start(s1, set);
	end = find_end(&s1[start], set);
	result = ft_substr(s1, start, end);
	return (result);
}
