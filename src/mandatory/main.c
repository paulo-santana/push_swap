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

#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

void	int_array_to_stack(int *list, t_stack *stack, int list_size)
{
	int	*content;

	while (list_size--)
	{
		content = malloc(sizeof(int));
		if (content == NULL)
		{
			ft_stack_destroy(stack);
			quit_with_error();
		}
		*content = list[list_size];
		ft_stack_push(stack, content);
	}
}

int	main(int argc, char *argv[])
{
	int		*int_list;
	int		list_size;
	t_stack	*stack;

	if (argc == 1)
		quit_with_error();
	int_list = parse_arguments(argv + 1, argc - 1, &list_size);
	if (int_list == NULL)
		quit_with_error();
	stack = ft_stack_new();
	/* for (int i = 0; i < list_size; i++) */
	/* 	printf("num: %d\n", int_list[i]); */
	if (stack == NULL)
	{
		free(int_list);
		quit_with_error();
	}
	int_array_to_stack(int_list, stack, list_size);
	solve(stack);
	ft_stack_destroy(stack);
	free(int_list);
}
