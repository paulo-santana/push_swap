#include "ft_int_stack.h"

void	ft_int_stack_push(t_int_stack *stack, int value)
{
	ft_int_lstadd_front(&stack->top, ft_int_lstnew(value));
	stack->size++;
}
