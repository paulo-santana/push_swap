#include "libft.h"
#include "ft_int_list.h"
#include "push_swap.h"

static int	ft_int_lstsize(t_int_list *lst)
{
	int			size;
	t_int_list	*tmp;

	tmp = lst;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

static int	*list_to_array(t_int_list *list, int *out_size)
{
	int	size;
	int	*array;

	size = ft_int_lstsize(list);
	array = malloc(size * sizeof(char *));
	if (array == NULL)
		exit(2);
	*out_size = size;
	while (size--)
	{
		array[size] = list->value;
		list = list->next;
	}
	return (array);
}

static void	print_instruction(int instruction)
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

int	cancels_with(int instruction1, int instruction2)
{
	if (instruction1 == RA)
		return (instruction2 == RRA);
	if (instruction1 == RRA)
		return (instruction2 == RA);
	if (instruction1 == RB)
		return (instruction2 == RRB);
	if (instruction1 == RRB)
		return (instruction2 == RB);
	if (instruction1 == SA)
		return (instruction2 == SA);
	if (instruction1 == SB)
		return (instruction2 == SB);
	if (instruction1 == PA)
		return (instruction2 == PB);
	if (instruction1 == PB)
		return (instruction2 == PA);
	return (0);
}

void	optmize_instructions(int *instructions, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i + j < size)
	{
		if (cancels_with(instructions[i], instructions[i + j]))
		{
			instructions[i] = 0;
			instructions[i + j] = 0;
			j += 2;
			i--;
		}
		else
		{
			i = i + j;
			j = 1;
		}
	}
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
