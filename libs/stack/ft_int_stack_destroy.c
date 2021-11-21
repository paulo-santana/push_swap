#include "ft_int_stack.h"
#include "../list/ft_int_list.h"

void	ft_int_stack_destroy(t_int_stack *stack)
{
	ft_int_lstclear(&stack->top);
	free(stack);
}
