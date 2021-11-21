#ifndef FT_INT_STACK
# define FT_INT_STACK

# include "ft_int_list.h"

typedef struct s_int_stack {
	t_int_list	*top;
	int			size;
} t_int_stack;

t_int_stack	*ft_int_stack_new();
void		ft_int_stack_push(t_int_stack *stack, int value);
int			ft_int_stack_pop(t_int_stack *stack);
void		ft_int_stack_destroy(t_int_stack *stack);

#endif // !FT_INT_STACK
