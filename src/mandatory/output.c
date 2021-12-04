/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:52:53 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/03 18:52:53 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_instruction(int instruction)
{
	char	*instructions[13];

	instructions[0] = "void";
	instructions[SA] = "sa";
	instructions[SB] = "sb";
	instructions[SS] = "ss";
	instructions[PA] = "pa";
	instructions[PB] = "pb";
	instructions[RA] = "ra";
	instructions[RB] = "rb";
	instructions[RR] = "rr";
	instructions[RRA] = "rra";
	instructions[RRB] = "rrb";
	instructions[RRR] = "rrr";
	instructions[12] = NULL;
	if (instructions[instruction] != 0)
		ft_putendl_fd(instructions[instruction], 1);
}

void	clear_instructions(t_int_list	*list)
{
	int	i;
	int	size;
	int	*instructions;

	instructions = list_to_array(list, &size);
	optmize_instructions(instructions, size);
	i = 0;
	while (i < size)
	{
		if (instructions[i] != 0)
			print_instruction(instructions[i++]);
		else
			i++;
	}
	free(instructions);
}
