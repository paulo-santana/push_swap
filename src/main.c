/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 09:35:42 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/22 09:43:13 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

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

void	parse_arguments(char *list[], int size)
{
	int				i;
	long long int	*int_list;

	i = 0;
	while (i < size)
		if (!ft_isnumber(list[i++]))
			quit_with_error();
	int_list = malloc(sizeof(long long int) * size);
	i = 0;
	while (i < size)
	{
		int_list[i] = ft_atol(list[i]);
		if (list_contains(int_list[i], int_list, i)
			|| int_list[i] > INT_MAX || int_list[i] < INT_MIN)
		{
			free(int_list);
			quit_with_error();
		}
		i++;
	}
	free(int_list);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		quit_with_error();
	parse_arguments(&argv[1], argc - 1);
}
