/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/13/25 14:19:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/04 13:16:02 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	get_min_max(t_int_stack *stack, int *out_min, int *out_max)
{
	int			i;
	t_int_list	*list;

	i = 0;
	*out_max = 0x80000000;
	*out_min = 0x7fffffff;
	list = stack->top;
	while (i++ < stack->size)
	{
		if (*out_min > list->value)
			*out_min = list->value;
		if (*out_max < list->value)
			*out_max = list->value;
		list = list->next;
	}
}

/**
 * Returns true if the stack pointed to by the array *stack is sorted
 **/

int	find_next_smallest(t_stack *stack)
{
	int		smallest;
	int		smallest_index;
	int		i;
	t_list	*list;

	if (stack->size == 1)
		return (0);
	list = stack->top;
	i = 0;
	smallest_index = 0;
	smallest = *(int *)list->content;
	while (list)
	{
		if (*(int *)list->content < smallest)
		{
			smallest = *(int *)list->content;
			smallest_index = i;
		}
		list = list->next;
		i++;
	}
	return (smallest_index);
}

int	is_sorted(t_data *data)
{
	int			true;
	int			false;
	t_int_list	*list;

	false = 0;
	true = 1;
	if (data->stack_b->size != 0)
		return (false);
	if (data->stack_a->top->value != data->min)
		return (false);
	if (data->stack_a->top == NULL)
		return (true);
	list = data->stack_a->top;
	while (list->next)
	{
		if (list->value > list->next->value)
			return (false);
		list = list->next;
	}
	return (true);
}

void	get_from_and_target(
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
