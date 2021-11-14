/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:19:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/25 14:19:25 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void min_max(t_stack *stack, int *out_min, int *out_max);

static int	find_best_move(t_stack *stack_a, t_stack *stack_b, int max, int min)
{
	t_list	*list;
	int		current;
	int		next;

	list = stack_a->top;
	current = *(int *)list->content;
	next = *(int *)list->next->content;
	if (current > next && (current != max || next != min))
		return print_swap(stack_a, 'a');
	else
		return print_rotate(stack_a, 'a');
	return (1);
	(void)stack_b;
}

void	solve(t_stack *stack_a)
{
	t_stack	*stack_b;
	int		min;
	int		max;

	if (stack_a->size == 1)
		return ;
	stack_b = ft_stack_new();
	min_max(stack_a, &min, &max);
	while (!is_sorted(stack_a) || stack_b->size != 0)
		find_best_move(stack_a, stack_b, max, min);
	ft_stack_destroy(stack_b);
}
