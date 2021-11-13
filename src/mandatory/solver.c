/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:19:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/25 14:19:25 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

/**
 * Returns true if the stack pointed to by the array *stack is sorted
 **/

int	is_sorted(t_stack *stack)
{
	t_list	*list;
	int		i;

	i = 1;
	list = stack->top;
	while (i < stack->size)
	{
		if (*(int *)list->content > *(int *)list->next->content)
			return (0);
		i++;
		list = list->next;
	}
	return (1);
}

static int	find_best_move(t_stack *stack_a, t_stack *stack_b)
{
	if (*(int *)stack_a->top->content > *(int *)stack_a->top->next->content)
		print_swap(stack_a, 'a');
	return (1);
	(void)stack_b;
}

void	solve(t_stack *stack_a)
{
	t_stack	*stack_b;

	if (stack_a->size == 1)
		return ;
	stack_b = ft_stack_new();
	while (!is_sorted(stack_a) || stack_b->size != 0)
		find_best_move(stack_a, stack_b);
	ft_stack_destroy(stack_b);
}
