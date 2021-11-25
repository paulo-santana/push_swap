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
# include "libft.h"
# include "ft_int_list.h"
# include "ft_int_stack.h"

typedef struct s_data {
	t_int_stack	*stack_a;
	t_int_stack	*stack_b;
	int			*solved_array;
	int			solved_array_size;
	int			min;
	int			max;
}	t_data;

void	solve(t_data *data);
void	quit_with_error(void);
int		*parse_arguments(char *list[], int str_list_size, int *new_list_size);
void	free_split(char **list);
int		validate_elements(char **list);
int		is_sorted(t_int_stack *stack, int min, int max);
void	get_min_max(t_int_stack *stack, int *out_min, int *out_max);

void	ps_push(t_int_stack *from, t_int_stack *to);
void	ps_swap(t_int_stack *stack);
void	ps_rotate(t_int_stack *stack);
void	ps_reverse_rotate(t_int_stack *stack);

int		print_swap(t_int_stack *stack, char target_id);
int		print_push(t_int_stack *from, t_int_stack *to, char target_id);
int		print_rotate(t_int_stack *stack, char target_id, int amount);
int		print_reverse_rotate(t_int_stack *stack, char target_id, int amount);

int		*quick_sort(int *array, int size);

#endif
