/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:19:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/01 12:33:31 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	do_compare(t_int_stack *from, int pivot)
{
	if (from->id == 'a')
		return (from->top->value < pivot);
	else
		return (from->top->value >= pivot);
}

static int	do_break(
	t_int_stack *from,
	t_int_stack *target,
	t_range *range,
	t_data *data)
{
	int			i;
	int			pivot;
	int			rotate_counter;

	i = range->start;
	pivot = data->solved_array[(range->start + range->end) / 2];
	rotate_counter = 0;
	while (i++ < range->end && from->size > 2)
	{
		if (do_compare(from, pivot))
			run_push(from, target, target->id, data);
		else
		{
			run_rotate(from, from->id, 1, data);
			rotate_counter++;
		}
	}
	return (rotate_counter);
}

static int	break_in_half(
	t_int_stack *from,
	t_int_stack *target,
	t_range *range,
	t_data *data)
{
	int		should_rr;
	int		rotate_counter;
	int		can_break_from_bottom;

	should_rr = 0;
	can_break_from_bottom = 0;
	if (range->end - range->start != from->size)
		should_rr = 1;
	rotate_counter = do_break(from, target, range, data);
	if (should_rr)
	{
		if (rotate_counter > 2 && from->id == 'a')
			can_break_from_bottom = 1;
		else
			run_reverse_rotate(from, from->id, rotate_counter, data);
	}
	return (can_break_from_bottom);
}

void	break_from_bottom(
	t_int_stack *from,
	t_int_stack *target,
	t_range *range,
	t_data *data)
{
	int	pivot;
	int	i;

	i = range->start;
	pivot = data->solved_array[(range->start + range->end) / 2];
	while (i++ < range->end)
	{
		run_reverse_rotate(from, from->id, 1, data);
		if (from->top->value < pivot)
			run_push(from, target, target->id, data);
	}
	data->can_break_from_bottom = 0;
}

void	solve(t_data *data, int start, int end, char current_stack)
{
	int			pivot_index;
	t_range		range;
	t_int_stack	*from;
	t_int_stack	*target;

	if (is_sorted(data))
		return ;
	pivot_index = (start + end) / 2;
	if (end - start > 3)
	{
		range.start = start;
		range.end = end;
		get_from_and_target(&from, &target, &current_stack, data);
		if (data->can_break_from_bottom && current_stack == 'a')
			break_from_bottom(from, target, &range, data);
		else
			data->can_break_from_bottom = break_in_half(
					from, target, &range, data);
		solve(data, pivot_index, end, 'a');
		solve(data, start, pivot_index, 'b');
	}
	else if (current_stack == 'a')
		solve_small(data->stack_a, data, end - start);
	else
		solve_small(data->stack_b, data, end - start);
}
