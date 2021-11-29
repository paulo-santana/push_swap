/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:11:00 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/28 17:11:00 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "bonus.h"
#include <stdio.h>

void	fill_stack(t_int_stack *stack, int *int_list, int int_list_size)
{
	int		content;

	while (int_list_size--)
	{
		content = int_list[int_list_size];
		ft_int_stack_push(stack, content);
	}
}

static int	is_valid(char *instruction)
{
	int		i;
	char	*valid_instructions[12];

	i = 0;
	init_instructions(valid_instructions);
	while (valid_instructions[i])
	{
		if (ft_strncmp(valid_instructions[i], instruction,
				ft_strlen(valid_instructions[i]) + 1) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	apply_command(char *command, t_int_stack *stack_a, t_int_stack *stack_b)
{
	if (!ft_strncmp(command, "pa", 3))
		ps_push(stack_b, stack_a);
	else if (!ft_strncmp(command, "pb", 3))
		ps_push(stack_a, stack_b);
	if (!ft_strncmp(command, "sa", 3) || !ft_strncmp(command, "ss", 3))
		ps_swap(stack_a);
	if (!ft_strncmp(command, "sb", 3) || !ft_strncmp(command, "ss", 3))
		ps_swap(stack_b);
	if (!ft_strncmp(command, "ra", 3) || !ft_strncmp(command, "rr", 3))
		ps_rotate(stack_a);
	if (!ft_strncmp(command, "rb", 3) || !ft_strncmp(command, "rr", 3))
		ps_rotate(stack_b);
	if (!ft_strncmp(command, "rra", 4) || !ft_strncmp(command, "rrr", 4))
		ps_reverse_rotate(stack_a);
	if (!ft_strncmp(command, "rrb", 4) || !ft_strncmp(command, "rrr", 4))
		ps_reverse_rotate(stack_b);
}

/**
 * Read the instructions from the stdin and apply them to the stack
 **/

void	read_instructions(t_int_stack *stack_a, t_int_stack *stack_b)
{
	int		result;
	char	*instruction;

	while (1)
	{
		result = get_next_line(0, &instruction);
		if (result != 1)
			break ;
		if (!is_valid(instruction))
		{
			ft_putendl_fd("Error", 2);
			ft_int_stack_destroy(stack_a);
			ft_int_stack_destroy(stack_b);
			free(instruction);
			exit(1);
		}
		apply_command(instruction, stack_a, stack_b);
		print_stack("a", stack_a);
		print_stack("b", stack_b);
		ft_putendl_fd("", 1);
		free(instruction);
	}
	if (result != -1)
		free(instruction);
}

int	main(int argc, char *argv[])
{
	int			*int_list;
	int			int_list_size;
	t_int_stack	*stack_a;
	t_int_stack	*stack_b;
	int			result;

	if (argc == 1)
		quit_with_error();
	int_list = parse_arguments(&argv[1], argc - 1, &int_list_size);
	stack_a = ft_int_stack_new();
	if (stack_a == NULL)
		return (free(int_list), 4);
	stack_b = ft_int_stack_new();
	if (stack_b == NULL)
		return (ft_int_stack_destroy(stack_a), free(int_list), 4);
	fill_stack(stack_a, int_list, int_list_size);
	free(int_list);
	print_stack("a", stack_a);
	print_stack("b", stack_b);
	read_instructions(stack_a, stack_b);
	result = get_result(stack_a, stack_b);
	print_result(result);
	ft_int_stack_destroy(stack_a);
	ft_int_stack_destroy(stack_b);
	exit(!result);
}
