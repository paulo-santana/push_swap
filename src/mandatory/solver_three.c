/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:55:33 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/27 19:02:56 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int_list.h"
#include "ft_int_stack.h"
#include "push_swap.h"

static void	solve_three_ascending(t_int_stack *stack, t_data *data);

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

static void	get_first_three(
		t_int_stack *stack, int *current, int *next, t_int_list **third)
{
	*current = stack->top->value;
	*next = stack->top->next->value;
	*third = stack->top->next->next;
}

static void	swap_2nd_3rd(t_int_stack *stack)
{
	print_rotate(stack, stack->id, 1);
	print_swap(stack, stack->id);
	print_reverse_rotate(stack, stack->id, 1);
}

static void	put_first_on_third(t_int_stack *stack)
{
	print_swap(stack, stack->id);
	print_rotate(stack, stack->id, 1);
	print_swap(stack, stack->id);
	print_reverse_rotate(stack, stack->id, 1);
}

static void	solve_three_ascending_helper(t_int_stack *stack, t_data *data)
{
	int			current;
	int			next;
	t_int_list	*third;

	get_first_three(stack, &current, &next, &third);
	if (current < next && current < third->value)
	{
		if (next > third->value)
			swap_2nd_3rd(stack);
	}
	else if (current > next && next < third->value)
		print_swap(stack, stack->id);
	else if (current > next && current > third->value)
		put_first_on_third(stack);
	else if (current < next && next > third->value)
		swap_2nd_3rd(stack);
	solve_three_ascending(stack, data);
}

static void	solve_three_ascending(t_int_stack *stack, t_data *data)
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
			print_swap(stack, stack->id);
	}
	else if (third->next == NULL)
	{
		if (current > next || current > third->value)
			print_rotate(stack, stack->id, 1);
		else if (next == data->max && next > third->value)
			print_reverse_rotate(stack, stack->id, 1);
	}
	else
		return (solve_three_ascending_helper(stack, data));
	solve_three_ascending(stack, data);
}

static void	solve_three_descending(t_int_stack *stack, t_data *data);

static void	solve_three_descending_helper(t_int_stack *stack, t_data *data)
{
	int			current;
	int			next;
	t_int_list	*third;

	get_first_three(stack, &current, &next, &third);
	if (current > next && current > third->value)
	{
		if (next < third->value)
			swap_2nd_3rd(stack);
	}
	else if (current < next && next > third->value)
		print_swap(stack, stack->id);
	else if (current < next && current < third->value)
		put_first_on_third(stack);
	else if (current > next && next < third->value)
		swap_2nd_3rd(stack);
	solve_three_descending(stack, data);
}

static void	solve_three_descending(t_int_stack *stack, t_data *data)
{
	int			second;
	int			first;
	t_int_list	*third;

	get_first_three(stack, &first, &second, &third);
	if (first > second && second > third->value)
		return ;
	if (third->value < first && third->value < second)
	{
		if (first < second)
			print_swap(stack, stack->id);
	}
	else if (third->next == NULL)
	{
		if (first < second || first < third->value)
			print_rotate(stack, stack->id, 1);
		else if (second == data->min && second < third->value)
			print_reverse_rotate(stack, stack->id, 1);
	}
	else
		return (solve_three_descending_helper(stack, data));
	solve_three_descending(stack, data);
}

void	solve_small(t_int_stack *stack, t_data *data, int size)
{
	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	if (size == 2 || stack->top->next->next == NULL)
		return (solve_these_two(stack));
	if (stack->id == 'a')
		solve_three_ascending(stack, data);
	else
		solve_three_descending(stack, data);
}
