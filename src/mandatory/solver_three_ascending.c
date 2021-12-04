/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_three_ascending.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:09:24 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/04 13:09:24 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	put_first_on_third(t_int_stack *stack, t_data *data)
{
	run_swap(stack, stack->id, data);
	run_rotate(stack, stack->id, 1, data);
	run_swap(stack, stack->id, data);
	run_reverse_rotate(stack, stack->id, 1, data);
}

static void	swap_2nd_3rd(t_int_stack *stack, t_data *data)
{
	run_rotate(stack, stack->id, 1, data);
	run_swap(stack, stack->id, data);
	run_reverse_rotate(stack, stack->id, 1, data);
}

void	solve_three_ascending(t_int_stack *stack, t_data *data)
{
	int			next;
	int			current;
	t_int_list	*third;

	get_first_three(stack, &current, &next, &third);
	if (current < next && next < third->value)
		return ;
	if (third->value > current && third->value > next)
	{
		if (current > next)
			run_swap(stack, stack->id, data);
	}
	else if (third->next == NULL)
	{
		if (current > next || current > third->value)
			run_rotate(stack, stack->id, 1, data);
		else if (next == data->max && next > third->value)
			run_reverse_rotate(stack, stack->id, 1, data);
	}
	else
		return (solve_three_ascending_helper(stack, data));
	solve_three_ascending(stack, data);
}

void	solve_three_ascending_helper(t_int_stack *stack, t_data *data)
{
	int			current;
	int			next;
	t_int_list	*third;

	get_first_three(stack, &current, &next, &third);
	if (current < next && current < third->value)
	{
		if (next > third->value)
			return (swap_2nd_3rd(stack, data));
	}
	else if (current > next && next < third->value)
		run_swap(stack, stack->id, data);
	else if (current > next && current > third->value)
		put_first_on_third(stack, data);
	else if (current < next && next > third->value)
		swap_2nd_3rd(stack, data);
	solve_three_ascending(stack, data);
}
