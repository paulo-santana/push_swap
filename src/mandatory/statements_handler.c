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

#include "libft.h"

void	ps_push(t_stack *from, t_stack *to)
{
	void	*content;

	if (from->top)
	{
		content = ft_stack_pop(from);
		ft_stack_push(to, content);
	}
}

void	ps_swap(t_stack *stack)
{	
	void	*content1;
	void	*content2;

	if (stack->top == NULL)
		return ;
	if (stack->top->next == NULL)
		return ;
	content1 = ft_stack_pop(stack);
	content2 = ft_stack_pop(stack);
	ft_stack_push(stack, content1);
	ft_stack_push(stack, content2);
}

void	ps_rotate(t_stack *stack)
{
	void	*content;

	if (stack->top == NULL)
		return ;
	if (stack->top->next == NULL)
		return ;
	content = ft_stack_pop(stack);
	ft_lstadd_back(&stack->top, ft_lstnew(content));
}

void	ps_reverse_rotate(t_stack *stack)
{
	t_list	*second_last;
	void	*content;

	if (stack->top == NULL)
		return ;
	if (stack->top->next == NULL)
		return ;
	second_last = stack->top;
	while (second_last->next->next)
		second_last = second_last->next;
	content = second_last->next->content;
	ft_lstadd_front(&stack->top, ft_lstnew(content));
	ft_lstdelone(second_last->next, ft_stack_do_nothing);
	second_last->next = NULL;
}
