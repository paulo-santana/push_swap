/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 09:35:42 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/22 09:43:13 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_int_stack.h"
#include <stdio.h>

void	int_array_to_stack(int *list, t_int_stack *stack, int list_size)
{
	while (list_size--)
	{
		ft_int_stack_push(stack, list[list_size]);
	}
}

static void	init_data(t_data *data, t_int_stack *stack_a)
{
	int			min;
	int			max;
	t_int_stack	*stack_b;

	stack_b = ft_int_stack_new();
	if (stack_b == NULL)
		exit(1);
	data->stack_a = stack_a;
	data->stack_b = stack_b;
	get_min_max(stack_a, &min, &max);
	data->min = min;
	data->max = max;
}

int	main(int argc, char *argv[])
{
	int		*int_list;
	int		list_size;
	t_int_stack	*stack;
	t_data	data;

	if (argc == 1)
		quit_with_error();
	int_list = parse_arguments(argv + 1, argc - 1, &list_size);
	if (int_list == NULL)
		quit_with_error();
	stack = ft_int_stack_new();
	if (stack == NULL)
	{
		free(int_list);
		quit_with_error();
	}
	int_array_to_stack(int_list, stack, list_size);
	quick_sort(int_list, list_size);
	init_data(&data, stack);
	data.solved_array = int_list;
	data.solved_array_size = list_size;
	solve(&data);
	ft_int_stack_destroy(stack);
	free(int_list);
}
