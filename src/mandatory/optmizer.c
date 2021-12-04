/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optmizer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:04:36 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/04 13:04:36 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_int_list.h"
#include "push_swap.h"

static int	ft_int_lstsize(t_int_list *lst)
{
	int			size;
	t_int_list	*tmp;

	tmp = lst;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

int	*list_to_array(t_int_list *list, int *out_size)
{
	int	size;
	int	*array;

	size = ft_int_lstsize(list);
	array = malloc(size * sizeof(char *));
	if (array == NULL)
		exit(2);
	*out_size = size;
	while (size--)
	{
		array[size] = list->value;
		list = list->next;
	}
	return (array);
}

int	cancels_with(int instruction1, int instruction2)
{
	if (instruction1 == RA)
		return (instruction2 == RRA);
	if (instruction1 == RRA)
		return (instruction2 == RA);
	if (instruction1 == RB)
		return (instruction2 == RRB);
	if (instruction1 == RRB)
		return (instruction2 == RB);
	if (instruction1 == SA)
		return (instruction2 == SA);
	if (instruction1 == SB)
		return (instruction2 == SB);
	if (instruction1 == PA)
		return (instruction2 == PB);
	if (instruction1 == PB)
		return (instruction2 == PA);
	return (0);
}

void	optmize_instructions(int *instructions, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i + j < size)
	{
		if (cancels_with(instructions[i], instructions[i + j]))
		{
			instructions[i] = 0;
			instructions[i + j] = 0;
			j += 2;
			i--;
		}
		else
		{
			i = i + j;
			j = 1;
		}
	}
}
