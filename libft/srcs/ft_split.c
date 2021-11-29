/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:46:30 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/27 01:00:22 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	get_next_word(char const *s, char c)
{
	size_t	limit;

	limit = 0;
	while (s[limit] && s[limit] != c)
		limit++;
	return (limit);
}

static char	**free_result(char **result, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(result[i++]);
	free(result);
	return (NULL);
}

static size_t	count_splits(char const *s, char c)
{
	size_t	i;
	size_t	splits;

	splits = 0;
	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i])
	{
		if (!i)
			splits++;
		else if (s[i - 1] == c && s[i] != c)
			splits++;
		i++;
	}
	return (splits);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	pieces;
	size_t	i;
	size_t	limit;

	pieces = count_splits(s, c);
	result = malloc(sizeof(char *) * (pieces + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < pieces)
	{
		while (*s && *s == c)
			s++;
		limit = get_next_word(s, c);
		result[i] = ft_substr(s, 0, limit);
		if (!result[i])
			return (free_result(result, i));
		s += limit + 1;
		i++;
	}
	result[pieces] = NULL;
	return (result);
}
