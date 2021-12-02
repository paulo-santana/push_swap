#include "ft_int_list.h"
#include "ft_int_stack.h"
#include "libft.h"
#include "push_swap.h"

static void	solve_three_ascending(t_int_stack *stack, t_data *data);

static void	solve_these_two(t_int_stack *stack, t_data *data)
{
	if (stack->id == 'a')
	{
		if (stack->top->value > stack->top->next->value)
			run_swap(stack, stack->id, data);
	}
	else
	{
		if (stack->top->value < stack->top->next->value)
			run_swap(stack, stack->id, data);
		run_push(data->stack_b, data->stack_a, 'a', data);
		run_push(data->stack_b, data->stack_a, 'a', data);
	}
}

static void	get_first_three(
		t_int_stack *stack, int *current, int *next, t_int_list **third)
{
	*current = stack->top->value;
	*next = stack->top->next->value;
	*third = stack->top->next->next;
}

static void	swap_2nd_3rd(t_int_stack *stack, t_data *data)
{
	run_rotate(stack, stack->id, 1, data);
	run_swap(stack, stack->id, data);
	run_reverse_rotate(stack, stack->id, 1, data);
}

static void	put_first_on_third(t_int_stack *stack, t_data *data)
{
	run_swap(stack, stack->id, data);
	run_rotate(stack, stack->id, 1, data);
	run_swap(stack, stack->id, data);
	run_reverse_rotate(stack, stack->id, 1, data);
}

static void	solve_three_ascending_helper(t_int_stack *stack, t_data *data)
{
	int			current;
	int			next;
	t_int_list	*third;

	get_first_three(stack, &current, &next, &third);
	if (current < next && current < third->value)
	{
		if (next > third->value)
			return (swap_2nd_3rd(stack, data));
	}
	else if (current > next && next < third->value)
		run_swap(stack, stack->id, data);
	else if (current > next && current > third->value)
		put_first_on_third(stack, data);
	else if (current < next && next > third->value)
		swap_2nd_3rd(stack, data);
	solve_three_ascending(stack, data);
}

static void	solve_three_ascending(t_int_stack *stack, t_data *data)
{
	int			next;
	int			current;
	t_int_list	*third;

	get_first_three(stack, &current, &next, &third);
	if (current < next && next < third->value)
		return ;
	if (third->value > current && third->value > next)
	{
		if (current > next)
			run_swap(stack, stack->id, data);
	}
	else if (third->next == NULL)
	{
		if (current > next || current > third->value)
			run_rotate(stack, stack->id, 1, data);
		else if (next == data->max && next > third->value)
			run_reverse_rotate(stack, stack->id, 1, data);
	}
	else
		return (solve_three_ascending_helper(stack, data));
	solve_three_ascending(stack, data);
}

static void	solve_three_descending(t_int_stack *stack, t_data *data);

static void	just_send_to_a(t_int_stack *stack_a, t_int_stack *stack_b,
		t_data *data)
{
	run_push(stack_b, stack_a, 'a', data);
	run_push(stack_b, stack_a, 'a', data);
	run_push(stack_b, stack_a, 'a', data);
}

static void	solve_three_descending_helper(t_int_stack *stack_b, t_data *data)
{
	int			first;
	int			second;
	t_int_list	*third;

	get_first_three(stack_b, &first, &second, &third);
	if (first < second)
	{
		run_push(stack_b, data->stack_a, 'a', data);
		if (second < third->value)
			run_swap(stack_b, stack_b->id, data);
		run_push(stack_b, data->stack_a, 'a', data);
		run_swap(data->stack_a, 'a', data);
		run_push(stack_b, data->stack_a, 'a', data);
		run_swap(data->stack_a, 'a', data);
	}
	else
	{
		run_push(stack_b, data->stack_a, 'a', data);
		run_swap(data->stack_b, 'b', data);
		run_push(stack_b, data->stack_a, 'a', data);
		run_swap(data->stack_a, 'a', data);
		run_push(stack_b, data->stack_a, 'a', data);
	}
}

static void solve_biggest_on_top(t_int_stack *b, t_int_stack *a, t_data *data)
{
	run_push(b, a, 'a', data);
	if (b->top->value < b->top->next->value)
		run_swap(b, 'b', data);
	run_push(b, a, 'a', data);
	run_push(b, a, 'a', data);
}

static void	solve_three_descending(t_int_stack *stack_b, t_data *data)
{
	int			second;
	int			first;
	t_int_list	*third;

	get_first_three(stack_b, &first, &second, &third);
	if (first > second && second > third->value)
		return (just_send_to_a(data->stack_a, data->stack_b, data));
	if (first > second && first > third->value)
		return (solve_biggest_on_top(stack_b, data->stack_a, data));
	if (second > first && second > third->value)
	{
		run_swap(stack_b, stack_b->id, data);
		run_push(stack_b, data->stack_a, 'a', data);
		if (first < third->value)
			run_swap(stack_b, stack_b->id, data);
		run_push(stack_b, data->stack_a, 'a', data);
		run_push(stack_b, data->stack_a, 'a', data);
	}
	else
		return (solve_three_descending_helper(stack_b, data));
}

void	solve_small(t_int_stack *stack, t_data *data, int size)
{
	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	if (stack->id == 'a' && data->can_break_from_bottom)
	{
		data->can_break_from_bottom = 0;
		run_reverse_rotate(stack, stack->id, size, data);
	}
	if (size == 2 || stack->top->next->next == NULL)
		return (solve_these_two(stack, data));
	if (stack->id == 'a')
		solve_three_ascending(stack, data);
	else
		solve_three_descending(stack, data);
}
