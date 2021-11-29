/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:18:39 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/27 13:26:33 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_stack_push(t_stack *stack, void *content)
{
	ft_lstadd_front(&stack->top, ft_lstnew(content));
	stack->size++;
}
