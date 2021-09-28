/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:03:21 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/27 20:03:21 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include "libft.h"

void	ps_push(t_stack *from, t_stack *to);
void	ps_swap(t_stack *stack);
void	print_stack(char *id, t_stack *stack);

#endif
