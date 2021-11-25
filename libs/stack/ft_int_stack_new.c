/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_stack_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:52:22 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/22 09:52:22 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int_stack.h"
#include "libft.h"

t_int_stack	*ft_int_stack_new(void)
{
	t_int_stack	*stack;

	stack = ft_calloc(1, sizeof(t_int_stack));
	return (stack);
}
