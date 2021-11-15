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

void get_min_max(t_stack *stack, int *out_min, int *out_max)
{
	int		i;
	t_list	*list;

	i = 0;
	*out_max = 0xffffffff;
	*out_min = 0x7fffffff;
	list = stack->top;
	while (i++ < stack->size)
	{
		if (*out_min > *(int *)list->content)
			*out_min = *(int *)list->content;
		if (*out_max < *(int *)list->content)
			*out_max = *(int *)list->content;
		list = list->next;
	}
}

/**
 * Returns true if the stack pointed to by the array *stack is sorted
 **/

int	is_sorted(t_stack *stack, int min, int max)
{
	t_list	*list;
	int		current;
	int		next;

	if (stack->top == NULL)
		return (1);
	if (stack->size <= 1)
		return (1);
	list = stack->top;
	current = *(int *)list->content;
	next = *(int *)list->next->content;
	while (list->next)
	{
		if (current > next && (current != max || next != min))
			return (0);
		list = list->next;
		current = *(int *)list->content;
		if (list->next)
			next = *(int *)list->next->content;
	}
	if (*(int *)list->content > *(int *)stack->top->content
			&& (*(int *)list->content != max || *(int *)stack->top->content != min))
		return (0);
	return (1);
}
