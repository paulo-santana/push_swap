#include "ft_int_list.h"

void	ft_int_lstadd_front(t_int_list **list, t_int_list *new)
{
	new->next = *list;
	*list = new;
}
