/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:39:10 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/23 21:39:10 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa(int n)
{
	char			*result;
	long long int	nb;
	size_t			len;
	int				is_negative;

	is_negative = n < 0;
	nb = n;
	if (is_negative)
		nb = -nb;
	len = 1;
	while (n / 10 != 0 && len++)
		n = n / 10;
	result = malloc(sizeof(char) * (len + 1 + is_negative));
	if (!result)
		return (NULL);
	result[len + is_negative] = '\0';
	while (len-- != 0)
	{
		result[len + is_negative] = nb % 10 + '0';
		nb /= 10;
	}
	if (is_negative)
		result[0] = '-';
	return (result);
}
