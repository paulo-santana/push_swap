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

void	init_instructions(char *instructions[12])
{
	instructions[0] = "sa";
	instructions[1] = "sb";
	instructions[2] = "ss";
	instructions[3] = "pa";
	instructions[4] = "pb";
	instructions[5] = "ra";
	instructions[6] = "rb";
	instructions[7] = "rr";
	instructions[8] = "rra";
	instructions[9] = "rrb";
	instructions[10] = "rrr";
	instructions[11] = NULL;
}
