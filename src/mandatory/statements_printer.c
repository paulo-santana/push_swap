/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:19:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/02 16:36:01 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

/**
 * Runs a swap instruction on the *stack and appends the instruction to the
 * instructions list. 
 */

void	run_swap(t_int_stack *stack, char target_id, t_data *data)
{
	int	instruction;

	if (target_id == 'a')
		instruction = SA;
	else
		instruction = SB;
	ps_swap(stack);
	ft_int_lstadd_front(&data->instructions, ft_int_lstnew(instruction));
}

/**
 * Runs a push instruction from the stack *from to the stack *to and appends
 * the instruction to the instructions list.
 */

void	run_push(
	t_int_stack *from,
	t_int_stack *to,
	char target_id,
	t_data *data)
{
	int	instruction;

	if (target_id == 'a')
		instruction = PA;
	else
		instruction = PB;
	ps_push(from, to);
	ft_int_lstadd_front(&data->instructions, ft_int_lstnew(instruction));
}

/**
 * Runs a rotate instruction on the stack *stack and appends it to the
 * instructions list.
 */

void	run_rotate(t_int_stack *stack, char target_id, int amount, t_data *data)
{
	int	instruction;

	if (target_id == 'a')
		instruction = RA;
	else
		instruction = RB;
	if (amount <= 0)
		return ;
	while (amount--)
	{
		ps_rotate(stack);
		ft_int_lstadd_front(&data->instructions, ft_int_lstnew(instruction));
	}
}

void	run_reverse_rotate(
	t_int_stack *stack,
	char target_id,
	int amount,
	t_data *data)
{
	int	instruction;

	if (target_id == 'a')
		instruction = RRA;
	else
		instruction = RRB;
	if (amount <= 0)
		return ;
	while (amount--)
	{
		ps_reverse_rotate(stack);
		ft_int_lstadd_front(&data->instructions, ft_int_lstnew(instruction));
	}
}
