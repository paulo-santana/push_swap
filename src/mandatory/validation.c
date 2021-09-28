/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:02:04 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/25 17:02:04 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

void	quit_with_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	list_contains(long long int item, long long int *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (list[i] == item)
			return (1);
		i++;
	}
	return (0);
}

long long int	*parse_arguments(char *list[], int size)
{
	int				i;
	long long int	*int_list;

	i = 0;
	while (i < size)
		if (!ft_isnumber(list[i++]))
			quit_with_error();
	int_list = ft_calloc(sizeof(long long int), size);
	while (i--)
	{
		int_list[i] = ft_atol(list[size - i - 1]);
		if (list_contains(int_list[i], int_list, i)
			|| int_list[i] > INT_MAX || int_list[i] < INT_MIN)
		{
			free(int_list);
			quit_with_error();
		}
	}
	return (int_list);
}
