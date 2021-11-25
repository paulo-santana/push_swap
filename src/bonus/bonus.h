/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:03:21 by psergio-          #+#    #+#             */
/*   Updated: 2021/11/22 09:46:08 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include "libft.h"
# include "push_swap.h"

void	print_stack(char *id, t_int_stack *stack);
int		get_result(t_int_stack *a, t_int_stack *b);
void	print_result(int ok);
int		checker_is_sorted(t_int_stack *stack);
void	init_instructions(char *instructions[12]);

#endif
