/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:20:16 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/25 15:06:57 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include "../libft/libft.h"

void			solve(t_stack *stack);
void			quit_with_error(void);
int				list_contains(
					long long int item, long long int *list, int size);
long long int	*parse_arguments(char *list[], int size);

#endif
