/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_stack_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:52:33 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/22 09:52:33 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int_stack.h"

void	ft_int_stack_push(t_int_stack *stack, int value)
{
	ft_int_lstadd_front(&stack->top, ft_int_lstnew(value));
	stack->size++;
}
