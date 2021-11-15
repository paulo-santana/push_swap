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

/**
 * Prints the best instruction based on the stacks current state.
 * Returns true if the movement have possibly been the last needed to 
 * sort the stack. To confirm the stack has been sorted, a full check is needed.
 */

static int	find_best_move(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	int	current;
	int	next;

	current = *(int *)stack_a->top->content;
	next = *(int *)stack_a->top->next->content;
	if (current > next && (current != max || next != min))
		return print_swap(stack_a, "sa");
	else
		return print_rotate(stack_a, "ra");
	(void)stack_b;
}

/**
 * Finds the smallest number in the stack and brings it to the head
 * with multiple rotate or reverse rotate instructions.
 *
 * */

static void	bring_to_front(t_stack *stack, int target)
{
	int		i;
	t_list	*list;
	char	*instruction;

	i = 0;
	list = stack->top;
	while (list)
	{
		if (*(int *)list->content == target)
			break;
		i++;
		list = list->next;
	}
	if (i > stack->size / 2)
	{
		i = stack->size - i;
		instruction = "rra";
	}
	else
		instruction = "ra";
	while (i--)
		ft_putendl_fd(instruction, 1);
}

void	solve(t_stack *stack_a)
{
	t_stack	*stack_b;
	int		min;
	int		max;
	int		could_be_sorted;

	if (stack_a->size == 1)
		return ;
	could_be_sorted = 1;
	stack_b = ft_stack_new();
	get_min_max(stack_a, &min, &max);
	while (!could_be_sorted ||
			!is_sorted(stack_a, min, max) || stack_b->size != 0)
		could_be_sorted = find_best_move(stack_a, stack_b, min, max);
	ft_stack_destroy(stack_b);
	bring_to_front(stack_a, min);
}
