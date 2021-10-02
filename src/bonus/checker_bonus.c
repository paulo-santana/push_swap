/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:30:59 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/28 01:03:06 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "bonus.h"

int	is_sorted(t_stack *stack)
{
	t_list	*list;
	int		i;

	i = 1;
	list = stack->top;
	while (i < stack->max_size)
	{
		if (*(int *)list->content > *(int *)list->next->content)
			return (0);
		i++;
		list = list->next;
	}
	return (1);
}

void	fill_stack(t_stack *stack, long long int *int_list)
{
	int		i;
	int		*content;
	t_list	*list;

	i = 0;
	list = NULL;
	while (i < stack->max_size)
	{
		content = malloc(sizeof(int));
		*content = int_list[i];
		ft_lstadd_front(&list, ft_lstnew(content));
		i++;
	}
	stack->top = list;
}

static int	is_valid(char *instruction)
{
	int			i;
	static char	*valid_instructions[] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr",
		NULL,
	};

	i = 0;
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

void	apply_command(char *command, t_stack *stack_a, t_stack *stack_b)
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

void	read_instructions(t_stack *stack_a, t_stack *stack_b)
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
			ft_stack_destroy(stack_a);
			ft_stack_destroy(stack_b);
			free(instruction);
			exit(1);
		}
		apply_command(instruction, stack_a, stack_b);
		print_stack("a", stack_a);
		print_stack("b", stack_b);
		free(instruction);
	}
	if (result != -1)
		free(instruction);
}

int	main(int argc, char *argv[])
{
	long long int	*int_list;
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				list_size;

	if (argc == 1)
		quit_with_error();
	list_size = argc - 1;
	int_list = parse_arguments(&argv[1], list_size);
	stack_a = ft_stack_new(list_size);
	if (stack_a == NULL)
		return (free(int_list), 4);
	stack_b = ft_stack_new(list_size);
	if (stack_b == NULL)
		return (ft_stack_destroy(stack_a), free(int_list), 4);
	fill_stack(stack_a, int_list);
	free(int_list);
	read_instructions(stack_a, stack_b);
	if (is_sorted(stack_a) && stack_b->top == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_stack_destroy(stack_a);
	ft_stack_destroy(stack_b);
}
