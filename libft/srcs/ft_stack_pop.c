/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:42:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/27 22:39:04 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_stack_pop(t_stack *stack)
{
	t_list	*top;
	t_list	*new_top;
	void	*content;

	top = stack->top;
	new_top = top->next;
	stack->top = new_top;
	top->next = NULL;
	content = top->content;
	ft_lstdelone(top, ft_stack_do_nothing);
	stack->size--;
	return (content);
}
