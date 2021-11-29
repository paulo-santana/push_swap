/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 01:37:32 by psergio-          #+#    #+#             */
/*   Updated: 2021/06/26 01:37:32 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_uitoa(unsigned int nbr)
{
	char			*result;
	int				len;
	unsigned int	aux;

	len = 1;
	aux = nbr;
	while (aux / 10 != 0 && len++)
		aux = aux / 10;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	while (len-- != 0)
	{
		result[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}
