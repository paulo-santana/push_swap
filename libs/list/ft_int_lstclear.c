/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_lstclear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:51:38 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/22 09:51:38 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
