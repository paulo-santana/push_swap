#include "ft_int_list.h"

void	ft_int_lstdelone(t_int_list *lst)
{
	free(lst);
}
