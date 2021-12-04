/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:02:04 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/04 15:04:43 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

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

static int	*make_int_list(char *str_list[], int list_size)
{
	int	i;
	int	list_is_valid;
	int	*int_list;

	list_is_valid = validate_elements(str_list);
	if (list_is_valid == 0)
	{
		free_split(str_list);
		quit_with_error();
	}
	int_list = malloc(sizeof(int) * list_size);
	if (int_list == NULL)
		exit(2);
	i = 0;
	while (i < list_size)
	{
		int_list[i] = ft_atoi(str_list[i]);
		i++;
	}
	return (int_list);
}

int	*parse_arguments(char *list[], int str_list_size, int *out_int_list_size)
{
	int		i;
	int		list_size;
	int		*int_list;
	char	**numbers;
	char	**full_str_list;

	i = 0;
	full_str_list = NULL;
	while (i < str_list_size)
	{
		if (ft_strlen(list[i]) == 0)
		{
			free_split(full_str_list);
			quit_with_error();
		}
		numbers = ft_split(list[i], ' ');
		merge_list(&full_str_list, numbers, &list_size);
		free(numbers);
		i++;
	}
	int_list = make_int_list(full_str_list, list_size);
	*out_int_list_size = list_size;
	free_split(full_str_list);
	return (int_list);
}
