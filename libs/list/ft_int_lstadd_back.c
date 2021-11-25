/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_lstadd_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:51:23 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/22 09:51:23 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else
		*list = new;
}
