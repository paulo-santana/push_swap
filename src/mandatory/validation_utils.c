/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 07:56:35 by psergio-          #+#    #+#             */
/*   Updated: 2021/10/22 07:56:35 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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

int	validate_elements(char **list)
{
	int		i;
	long	number_as_long;
	int		is_valid;

	i = 0;
	is_valid = 1;
	while (list[i])
	{
		if (!ft_isnumber(list[i]))
			is_valid = 0;
		number_as_long = ft_atol(list[i]);
		if (number_as_long > 2147483647 || number_as_long < -2147483648)
			is_valid = 0;
		if (!is_valid)
			break ;
		i++;
	}
	return (is_valid);
}

void	free_split(char **list)
{
	int	i;

	if (list == NULL)
		return ;
	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}
