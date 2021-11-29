/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:50:15 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/22 10:50:15 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long long int	ft_atol(const char *str)
{
	long long int	result;
	int				sign;
	int				i;

	i = 0;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (str[i] == '-' && ++i)
		sign = -1;
	else if (str[i] == '+')
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
	}
	return (result * sign);
}
