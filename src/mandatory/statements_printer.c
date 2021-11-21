/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:19:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/25 14:19:25 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/**
 * Runs a swap instruction on the *stack and prints the instruction on the
 * standard output. Returns true if the stack could be sorted after this
 * instruction.
 * */
int	print_swap(t_int_stack *stack, char *move)
{
	ps_swap(stack);
	ft_putendl_fd(move, 1);
	return (1);
}

int	print_push(t_int_stack *from, t_int_stack *to, char *move)
{
	ps_push(from, to);
	ft_putendl_fd(move, 1);
	return (0);
}

/**
 * Prints a rotate instruction based on the stack_id, and applies it on the
 * given stack. Returns true if the stack could be sorted after this
 * instruction.
 * */
int	print_rotate(t_int_stack *stack, char *move, int amount)
{
	if (amount <= 0)
		return 0;
	while (amount--)
	{
		ps_rotate(stack);
		ft_putendl_fd(move, 1);
	}
	return (0);
}

int	print_reverse_rotate(t_int_stack *stack, char *move, int amount)
{
	if (amount <= 0)
		return 0;
	while (amount--)
	{
		ps_reverse_rotate(stack);
		ft_putendl_fd(move, 1);
	}
	return (0);
}
