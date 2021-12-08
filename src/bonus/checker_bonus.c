/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:11:00 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/04 16:34:51 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "bonus.h"

static int	is_valid(char *instruction)
{
	int		i;
	char	*valid_instructions[13];

	i = 1;
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

static int	command_to_int(char *command, char *instructions[13])
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(command, instructions[i + 1], 4) == 0)
			return (i + 1);
		i++;
	}
	return (0);
}

void	apply_command(char *command, t_int_stack *stack_a, t_int_stack *stack_b)
{
	int		instruction;
	char	*instructions[13];

	init_instructions(instructions);
	instruction = command_to_int(command, instructions);
	if (instruction == PA)
		ps_push(stack_b, stack_a);
	else if (instruction == PB)
		ps_push(stack_a, stack_b);
	if (instruction == SA || instruction == SS)
		ps_swap(stack_a);
	if (instruction == SB || instruction == SS)
		ps_swap(stack_b);
	if (instruction == RA || instruction == RR)
		ps_rotate(stack_a);
	if (instruction == RB || instruction == RR)
		ps_rotate(stack_b);
	if (instruction == RRA || instruction == RRR)
		ps_reverse_rotate(stack_a);
	if (instruction == RRB || instruction == RRR)
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
		exit(0);
	int_list = parse_arguments(&argv[1], argc - 1, &int_list_size);
	stack_a = ft_int_stack_new();
	stack_b = ft_int_stack_new();
	if (stack_b == NULL || stack_a == NULL)
		exit(2);
	if (check_duplicates(int_list, int_list_size))
	{
		clear_data(stack_a, stack_b, int_list);
		quit_with_error();
	}
	fill_stack(stack_a, int_list, int_list_size);
	read_instructions(stack_a, stack_b);
	result = get_result(stack_a, stack_b);
	print_result(result);
	clear_data(stack_a, stack_b, int_list);
	exit(!result);
}
