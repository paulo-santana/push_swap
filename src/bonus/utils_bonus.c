#include "bonus.h"

int	checker_is_sorted(t_stack *stack)
{
	t_list	*list;

	if (stack->top == NULL)
		return (1);
	if (stack->size <= 1)
		return (1);
	list = stack->top;
	while (list->next)
	{
		if (*(int *)list->content > *(int *)list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}
