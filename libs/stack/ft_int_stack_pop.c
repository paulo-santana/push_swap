#include "ft_int_stack.h"

int	ft_int_stack_pop(t_int_stack *stack)
{
	t_int_list	*top;
	t_int_list	*new_top;
	int			value;

	top = stack->top;
	new_top = top->next;
	value = top->value;
	stack->top = new_top;
	stack->size--;
	free(top);
	return (value);
}
