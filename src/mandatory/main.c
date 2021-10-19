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

int	main(int argc, char *argv[])
{
	long long int	*int_list;
	t_stack			*stack;

	if (argc == 1)
		quit_with_error();
	int_list = parse_arguments(argv + 1, argc - 1);
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		free(int_list);
		quit_with_error();
	}
	solve(stack);
	free(stack);
}
