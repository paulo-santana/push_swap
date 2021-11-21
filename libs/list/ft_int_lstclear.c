#include "ft_int_list.h"

void	ft_int_lstclear(t_int_list **lst)
{
	t_int_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_int_lstdelone(*lst);
		*lst = tmp;
	}
}
