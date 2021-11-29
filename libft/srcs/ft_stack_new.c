/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:21:00 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/25 23:21:00 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_stack	*ft_stack_new(void)
{
	t_stack	*stack;

	stack = ft_calloc(sizeof(t_stack), 1);
	if (stack == NULL)
		return (NULL);
	return (stack);
}
