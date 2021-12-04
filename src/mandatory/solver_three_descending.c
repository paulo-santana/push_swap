/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_three_descending.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:13:51 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/04 13:13:51 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	just_send_to_a(t_int_stack *stack_a, t_int_stack *stack_b,
		t_data *data)
{
	run_push(stack_b, stack_a, 'a', data);
	run_push(stack_b, stack_a, 'a', data);
	run_push(stack_b, stack_a, 'a', data);
}

static void	solve_three_descending_helper(t_int_stack *stack_b, t_data *data)
{
	int			first;
	int			second;
	t_int_list	*third;

	get_first_three(stack_b, &first, &second, &third);
	if (first < second)
	{
		run_push(stack_b, data->stack_a, 'a', data);
		if (second < third->value)
			run_swap(stack_b, stack_b->id, data);
		run_push(stack_b, data->stack_a, 'a', data);
		run_swap(data->stack_a, 'a', data);
		run_push(stack_b, data->stack_a, 'a', data);
		run_swap(data->stack_a, 'a', data);
	}
	else
	{
		run_push(stack_b, data->stack_a, 'a', data);
		run_swap(data->stack_b, 'b', data);
		run_push(stack_b, data->stack_a, 'a', data);
		run_swap(data->stack_a, 'a', data);
		run_push(stack_b, data->stack_a, 'a', data);
	}
}

static void	solve_biggest_on_top(t_int_stack *b, t_int_stack *a, t_data *data)
{
	run_push(b, a, 'a', data);
	if (b->top->value < b->top->next->value)
		run_swap(b, 'b', data);
	run_push(b, a, 'a', data);
	run_push(b, a, 'a', data);
}

void	solve_three_descending(t_int_stack *stack_b, t_data *data)
{
	int			second;
	int			first;
	t_int_list	*third;

	get_first_three(stack_b, &first, &second, &third);
	if (first > second && second > third->value)
		return (just_send_to_a(data->stack_a, data->stack_b, data));
	if (first > second && first > third->value)
		return (solve_biggest_on_top(stack_b, data->stack_a, data));
	if (second > first && second > third->value)
	{
		run_swap(stack_b, stack_b->id, data);
		run_push(stack_b, data->stack_a, 'a', data);
		if (first < third->value)
			run_swap(stack_b, stack_b->id, data);
		run_push(stack_b, data->stack_a, 'a', data);
		run_push(stack_b, data->stack_a, 'a', data);
	}
	else
		return (solve_three_descending_helper(stack_b, data));
}
