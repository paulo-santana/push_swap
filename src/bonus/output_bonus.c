/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:45:23 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/27 19:45:23 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_stack(char *id, t_stack *stack)
{
	t_list	*list;
	int		fd;

	list = stack->top;
	fd = 1;
	ft_putstr_fd(id, fd);
	ft_putstr_fd(": ", fd);
	while (list)
	{
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(*(int *)list->content, fd);
		list = list->next;
	}
	ft_putchar_fd('\n', fd);
}
