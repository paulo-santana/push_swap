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

void min_max(t_stack *stack, int *out_min, int *out_max)
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

int	is_sorted(t_stack *stack)
{
	t_list	*list;

	list = stack->top;
	while (list->next)
	{
		if (*(int *)list->content > *(int *)list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}
