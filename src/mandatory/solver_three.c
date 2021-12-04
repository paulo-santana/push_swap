/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:08:13 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/04 13:08:13 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int_list.h"
#include "ft_int_stack.h"
#include "libft.h"
#include "push_swap.h"

static void	solve_these_two(t_int_stack *stack, t_data *data)
{
	if (stack->id == 'a')
	{
		if (stack->top->value > stack->top->next->value)
			run_swap(stack, stack->id, data);
	}
	else
	{
		if (stack->top->value < stack->top->next->value)
			run_swap(stack, stack->id, data);
		run_push(data->stack_b, data->stack_a, 'a', data);
		run_push(data->stack_b, data->stack_a, 'a', data);
	}
}

void	get_first_three(
		t_int_stack *stack, int *current, int *next, t_int_list **third)
{
	*current = stack->top->value;
	*next = stack->top->next->value;
	*third = stack->top->next->next;
}

void	solve_small(t_int_stack *stack, t_data *data, int size)
{
	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	if (stack->id == 'a' && data->can_break_from_bottom)
	{
		data->can_break_from_bottom = 0;
		run_reverse_rotate(stack, stack->id, size, data);
	}
	if (size == 2 || stack->top->next->next == NULL)
		return (solve_these_two(stack, data));
	if (stack->id == 'a')
		solve_three_ascending(stack, data);
	else
		solve_three_descending(stack, data);
}
