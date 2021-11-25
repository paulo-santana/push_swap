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

#include "ft_int_stack.h"
#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static int	send_smaller_half(t_data *data, int pivot)
{
	int	i;
	int	middle;

	i = data->stack_a->size;
	middle = data->solved_array[pivot];
	while (data->stack_a->size > 2 && i--)
	{
		if (data->stack_a->top->value < middle)
			print_push(data->stack_a, data->stack_b, data->stack_b->id);
		else
			print_rotate(data->stack_a, data->stack_a->id, 1);
	}
	return (0);
}

void	solve(t_data *data)
{
	int	last;
	int	pivot;

	pivot = 0;
	last = data->solved_array_size;
	while (data->stack_a->size > 2)
	{
		pivot = (pivot + last) / 2;
		send_smaller_half(data, pivot);
	}
}
