/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/13/25 14:19:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/25 14:19:25 by psergio-         ###   ########.fr       */
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

int	is_sorted(t_int_stack *stack, int min, int max)
{
	t_int_list	*list;
	int			current;
	int			next;

	if (stack->top == NULL)
		return (1);
	if (stack->size <= 1)
		return (1);
	list = stack->top;
	current = list->value;
	next = list->next->value;
	while (list->next)
	{
		if (current > next && (current != max || next != min))
			return (0);
		list = list->next;
		current = list->value;
		if (list->next)
			next = list->next->value;
	}
	if (list->value > stack->top->value
		&& (list->value != max || stack->top->value != min))
		return (0);
	return (1);
}

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
