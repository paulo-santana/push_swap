/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_stack_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:52:20 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/22 09:52:20 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int_stack.h"
#include "../list/ft_int_list.h"

void	ft_int_stack_destroy(t_int_stack *stack)
{
	ft_int_lstclear(&stack->top);
	free(stack);
}
