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
 * Returns true if the stack pointed to by the array *stack is sorted
 **/

static int	is_sorted(t_stack *stack)
{
	(void)stack;
	return (1);
}

static int	find_best_move(t_stack *stack)
{
	(void)stack;
	return (1);
}

void	solve(t_stack *stack)
{
	while (!is_sorted(stack))
		find_best_move(stack);
	ft_putendl_fd("solved!", 1);
}
