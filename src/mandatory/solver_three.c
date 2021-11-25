/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:55:33 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/24 21:32:30 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int_stack.h"
#include "push_swap.h"

static void	solve_these_two(t_int_stack *stack)
{
	if (stack->id == 'a')
	{
		if (stack->top->value > stack->top->next->value)
			print_swap(stack, stack->id);
	}
	else
	{
		if (stack->top->value < stack->top->next->value)
			print_swap(stack, stack->id);
	}
}

static void	solve_three_ascending(t_int_stack *stack, t_data *data)
{
	int			next;
	int			current;
	t_int_list	*third;

	current = stack->top->value;
	next = stack->top->next->value;
	third = stack->top->next->next;
	if (current < next && next < third->value)
		return ;
	if (third->value > current && third->value > next)
	{
		if (current > next)
			print_swap(stack, stack->id);
	}
	else if (third->next == NULL)
	{
		if (current > next || current > third->value)
			print_rotate(stack, stack->id, 1);
		else if (next == data->max && next > third->value)
			print_reverse_rotate(stack, stack->id, 1);
	}
	solve_three_ascending(stack, data);
}

void	solve_three(t_int_stack *stack, t_data *data)
{
	if (stack->top->next->next == NULL)
		return (solve_these_two(stack));
	if (stack->id == 'a')
		solve_three_ascending(stack, data);
}
