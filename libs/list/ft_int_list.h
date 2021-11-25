/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:51:13 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/22 09:51:13 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_LIST_H
# define FT_INT_LIST_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_int_list {
	struct s_int_list	*next;
	int					value;
}	t_int_list;

t_int_list	*ft_int_lstnew(int value);
void		ft_int_lstdelone(t_int_list *lst);
void		ft_int_lstclear(t_int_list **lst);
void		ft_int_lstadd_back(t_int_list **list, t_int_list *value);
void		ft_int_lstadd_front(t_int_list **list, t_int_list *value);

#endif // !FT_INT_LIST_H
