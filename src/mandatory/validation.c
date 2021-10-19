/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:02:04 by psergio-          #+#    #+#             */
/*   Updated: 2021/10/11 21:50:46 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

#include "../utils/utils.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int	list_contains(long long int item, long long int *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (list[i] == item)
			return (1);
		i++;
	}
	return (0);
}

int	is_valid(char **list)
{
	int	i;
	int	is_valid;

	i = 0;
	is_valid = 1;
	while (list[i])
	{
		if (!ft_isnumber(list[i]))
			is_valid = 0;
		i++;
	}
	return (is_valid);
}

void	free_split(char **list)
{
	int	i;

	if (list == NULL)
		return ;
	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

static int	get_split_size(char **list)
{
	int	i;

	if (list == NULL)
		return (0);
	i = 0;
	while (list[i])
		i++;
	return (i);
}

/*
 * Merges two NULL terminated arrays of strings in a new NULL terminated array.
 * Puts the size of the new array in the pointer *size.
 * */

static void	merge_list(char ***list1, char **list2, int *new_list_size)
{
	int		size;
	int		i;
	char	**new_list;

	size = get_split_size(*list1);
	size += get_split_size(list2);
	new_list = malloc(sizeof(char *) * (size + 1));
	new_list[size] = NULL;
	i = 0;
	size = 0;
	if (*list1)
		while ((*list1)[i])
			new_list[size++] = (*list1)[i++];
	i = 0;
	while (list2[i])
		new_list[size++] = list2[i++];
	free(*list1);
	*list1 = new_list;
	*new_list_size = size;
}

long long int	*parse_arguments(char *list[], int str_list_size,
		int *new_list_size)
{
	int		i;
	int		list_size;
	char	**numbers;
	char	**full_list;

	i = 0;
	full_list = NULL;
	while (i < str_list_size)
	{
		numbers = ft_split(list[i], ' ');
		merge_list(&full_list, numbers, &list_size);
		free(numbers);
		printf("list size: %d\n", list_size);
		i++;
	}
	print_list(full_list);
	*new_list_size = list_size;
	free_split(full_list);
	return (NULL);
}
