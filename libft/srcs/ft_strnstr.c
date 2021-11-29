/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:48:32 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/20 21:48:32 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	str_matches(char *str, const char *target)
{
	int	matches;
	int	to_find_pos;

	matches = 0;
	to_find_pos = 0;
	while (target[to_find_pos] != '\0')
	{
		if (target[to_find_pos] != str[to_find_pos])
		{
			matches = 0;
			break ;
		}
		else
			matches = 1;
		to_find_pos++;
	}
	return (matches);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	limit;
	int		matches;
	int		little_len;
	char	*match_start;

	i = 0;
	matches = 0;
	little_len = ft_strlen((char *)little);
	if (little_len == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	limit = len - little_len;
	while (i <= limit)
	{
		if (big[i] == 0)
			break ;
		match_start = (char *)&big[i];
		matches = str_matches(match_start, little);
		if (matches)
			return (match_start);
		i++;
	}
	return (0);
}
