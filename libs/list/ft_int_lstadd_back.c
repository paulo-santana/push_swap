#include "ft_int_list.h"

void	ft_int_lstadd_back(t_int_list **list, t_int_list *new)
{
	t_int_list	*last;

	if (!list)
		return ;
	last = *list;
	if (last)
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else {
		*list = new;
	}
}
