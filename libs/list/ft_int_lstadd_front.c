/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_lstadd_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:51:36 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/22 09:51:36 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int_list.h"

void	ft_int_lstadd_front(t_int_list **list, t_int_list *new)
{
	new->next = *list;
	*list = new;
}
