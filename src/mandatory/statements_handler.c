/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:22:23 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/27 19:03:59 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push(t_int_stack *from, t_int_stack *to)
{
	int	value;

	if (from->top)
	{
		value = ft_int_stack_pop(from);
		ft_int_stack_push(to, value);
	}
}

void	ps_swap(t_int_stack *stack)
{	
	int content1;
	int content2;

	if (stack->top == NULL)
		return ;
	if (stack->top->next == NULL)
		return ;
	content1 = ft_int_stack_pop(stack);
	content2 = ft_int_stack_pop(stack);
	ft_int_stack_push(stack, content1);
	ft_int_stack_push(stack, content2);
}

void	ps_rotate(t_int_stack *stack)
{
	int	value;

	if (stack->top == NULL)
		return ;
	if (stack->top->next == NULL)
		return ;
	value = ft_int_stack_pop(stack);
	ft_int_lstadd_back(&stack->top, ft_int_lstnew(value));
	stack->size++;
}

void	ps_reverse_rotate(t_int_stack *stack)
{
	t_int_list	*second_last;
	int			content;

	if (stack->top == NULL)
		return ;
	if (stack->top->next == NULL)
		return ;
	second_last = stack->top;
	while (second_last->next->next)
		second_last = second_last->next;
	content = second_last->next->value;
	ft_int_lstadd_front(&stack->top, ft_int_lstnew(content));
	ft_int_lstdelone(second_last->next);
	second_last->next = NULL;
}
