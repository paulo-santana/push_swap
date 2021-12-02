/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:19:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/02 14:37:23 by psergio-         ###   ########.fr       */
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
	char	*move;

	move = malloc(3);
	move[0] = 's';
	move[1] = target_id;
	move[2] = '\0';
	ps_swap(stack);
	ft_lstadd_front(&data->instructions, ft_lstnew(move));
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
	char	*move;

	move = malloc(3);
	if (move == NULL)
		exit (1);
	move[0] = 'p';
	move[1] = target_id;
	move[2] = '\0';
	ps_push(from, to);
	ft_lstadd_front(&data->instructions, ft_lstnew(move));
}

/**
 * Runs a rotate instruction on the stack *stack and appends it to the
 * instructions list.
 */

void	run_rotate(t_int_stack *stack, char target_id, int amount, t_data *data)
{
	char	*move;

	move = malloc(3);
	if (move == NULL)
		exit (1);
	move[0] = 'r';
	move[1] = target_id;
	move[2] = '\0';
	if (amount <= 0)
		return ;
	while (amount--)
	{
		ps_rotate(stack);
		ft_lstadd_front(&data->instructions, ft_lstnew(move));
	}
}

void	run_reverse_rotate(
	t_int_stack *stack,
	char target_id,
	int amount,
	t_data *data)
{
	char	*move;

	move = malloc(4);
	if (move == NULL)
		exit (1);
	move[0] = 'r';
	move[1] = 'r';
	move[2] = target_id;
	move[3] = '\0';
	if (amount <= 0)
		return ;
	while (amount--)
	{
		ps_reverse_rotate(stack);
		ft_lstadd_front(&data->instructions, ft_lstnew(move));
	}
}
