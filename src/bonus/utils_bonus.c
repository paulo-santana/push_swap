/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:48:12 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/22 09:48:12 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <stdio.h>

int	checker_is_sorted(t_int_stack *stack)
{
	t_int_list	*list;

	if (stack->top == NULL)
		return (1);
	if (stack->size <= 1)
		return (1);
	list = stack->top;
	while (list->next)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

void	init_instructions(char *instructions[13])
{
	instructions[0] = "void";
	instructions[SA] = "sa";
	instructions[SB] = "sb";
	instructions[SS] = "ss";
	instructions[PA] = "pa";
	instructions[PB] = "pb";
	instructions[RA] = "ra";
	instructions[RB] = "rb";
	instructions[RR] = "rr";
	instructions[RRA] = "rra";
	instructions[RRB] = "rrb";
	instructions[RRR] = "rrr";
	instructions[12] = NULL;
}

int	check_duplicates(int *list, int list_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < list_size)
	{
		j = i + 1;
		while (j < list_size)
		{
			if (list[i] == list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
