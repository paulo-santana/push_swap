#include "ft_int_stack.h"
#include "libft.h"

t_int_stack	*ft_int_stack_new()
{
	t_int_stack	*stack;

	stack = ft_calloc(1, sizeof(t_int_stack));
	return (stack);
}
