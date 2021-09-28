/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statements_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:22:23 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/27 19:03:59 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ps_push(t_stack *from, t_stack *to)
{
	void	*content;

	if (from->top)
	{
		content = ft_stack_pop(from);
		ft_stack_push(to, content);
	}
}
