#include "libft.h"

static char	**list_to_array(t_list *list, int *out_size)
{
	int		size;
	char	**array;

	size = ft_lstsize(list);
	array = malloc(size * sizeof(char *));
	if (array == NULL)
		exit(2);
	*out_size = size;
	while (size--)
	{
		array[size] = (char *)list->content;
		list = list->next;
	}
	return (array);
}

void	clear_instructions(t_list	*list)
{
	int		i;
	int		size;
	char	**instructions;

	instructions = list_to_array(list, &size);
	i = 0;
	while (i < size)
	{
		ft_putendl_fd(instructions[i++], 1);
	}
}
