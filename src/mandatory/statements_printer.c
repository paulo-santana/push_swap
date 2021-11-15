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
int	print_swap(t_stack *stack, char *move)
{
	ps_swap(stack);
	ft_putendl_fd(move, 1);
	return (1);
}

/**
 * Prints a rotate instruction based on the stack_id, and applies it on the
 * given stack. Returns true if the stack could be sorted after this
 * instruction.
 * */
int	print_rotate(t_stack *stack, char *move)
{
	ps_rotate(stack);
	ft_putendl_fd(move, 1);
	return (0);
}
