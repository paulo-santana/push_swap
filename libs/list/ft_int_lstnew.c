/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:48:24 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/27 09:48:24 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int_list.h"

t_int_list	*ft_int_lstnew(int value)
{
	t_int_list	*element;

	element = ft_calloc(1, sizeof(t_int_list));
	if (element == NULL)
		return (NULL);
	element->value = value;
	element->next = NULL;
	return (element);
}
