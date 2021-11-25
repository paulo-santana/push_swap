/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:45:23 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/22 09:46:17 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus.h"

void	print_stack(char *id, t_int_stack *stack)
{
	t_int_list	*list;
	int			fd;

	list = stack->top;
	fd = 1;
	ft_putstr_fd(id, fd);
	ft_putstr_fd(": ", fd);
	while (list)
	{
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(list->value, fd);
		list = list->next;
	}
	ft_putchar_fd('\n', fd);
}

int	get_result(t_int_stack *a, t_int_stack *b)
{
	return (checker_is_sorted(a) && b->top == NULL);
}

void	print_result(int ok)
{
	if (ok)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
