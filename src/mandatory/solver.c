/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:19:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/29 06:50:16 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int_stack.h"
#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

typedef struct s_range {
	int	start;
	int	end;
}	t_range;

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
	int	i;
	int	pivot;
	int	rotate_counter;

	i = range->start;
	pivot = data->solved_array[(range->start + range->end) / 2];
	rotate_counter = 0;
	while (i++ < range->end && from->size > 2)
	{
		if (do_compare(from, pivot))
			print_push(from, target, target->id);
		else
		{
			print_rotate(from, from->id, 1);
			rotate_counter++;
		}
	}
	return (rotate_counter);
}

static void	break_in_half(
	t_int_stack *from,
	t_int_stack *target,
	t_range *range,
	t_data *data)
{
	int		should_rr;
	int		rotate_counter;

	should_rr = 0;
	if (range->end - range->start != from->size)
		should_rr = 1;
	rotate_counter = do_break(from, target, range, data);
	if (should_rr)
		print_reverse_rotate(from, from->id, rotate_counter);
}

static void	get_from_and_target(
	t_int_stack **from,
	t_int_stack **target,
	char *current_stack,
	t_data *data)
{
	if (*current_stack == 'a')
	{
		*from = data->stack_a;
		*target = data->stack_b;
	}
	else
	{
		*from = data->stack_b;
		*target = data->stack_a;
	}
}

void	solve(t_data *data, int start, int end, char current_stack)
{
	int			pivot_index;
	t_range		range;
	int			i;
	t_int_stack	*from;
	t_int_stack	*target;

	pivot_index = (start + end) / 2;
	if (end - start > 3)
	{
		range.start = start;
		range.end = end;
		get_from_and_target(&from, &target, &current_stack, data);
		break_in_half(from, target, &range, data);
		solve(data, pivot_index, range.end, 'a');
		solve(data, range.start, pivot_index, 'b');
	}
	else if (current_stack == 'a')
		solve_small(data->stack_a, data, end - start);
	else
	{
		i = end - start;
		solve_small(data->stack_b, data, end - start);
		while (i--)
			print_push(data->stack_b, data->stack_a, 'a');
	}
}
