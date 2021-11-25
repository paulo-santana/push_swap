/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:51:59 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/22 09:51:59 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INT_STACK_H
# define FT_INT_STACK_H

# include "ft_int_list.h"

typedef struct s_int_stack {
	t_int_list	*top;
	int			size;
	char		id;
}	t_int_stack;

t_int_stack	*ft_int_stack_new(void);
void		ft_int_stack_push(t_int_stack *stack, int value);
int			ft_int_stack_pop(t_int_stack *stack);
void		ft_int_stack_destroy(t_int_stack *stack);

#endif // !FT_INT_STACK_H
