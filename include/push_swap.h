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

# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define RA 5
# define RB 6
# define RRA 7
# define RRB 8
# define SS 9
# define RR 10
# define RRR 11

typedef struct s_data {
	t_int_stack	*stack_a;
	t_int_stack	*stack_b;
	int			*solved_array;
	int			solved_array_size;
	int			min;
	int			max;
	int			can_break_from_bottom;
	t_int_list	*instructions;
}	t_data;

void	solve_small(t_int_stack *stack, t_data *data, int size);
void	solve(t_data *data, int start, int end, char current_stack);

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

void	run_swap(
			t_int_stack *stack, char target_id, t_data *data);
void	run_push(
			t_int_stack *from, t_int_stack *to, char target_id, t_data *data);
void	run_rotate(
			t_int_stack *stack, char target_id, int amount, t_data *data);
void	run_reverse_rotate(
			t_int_stack *stack, char target_id, int amount, t_data *data);

int		*quick_sort(int *array, int size);

void	clear_instructions(t_int_list	*list);

#endif
