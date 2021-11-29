/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 00:05:40 by psergio-          #+#    #+#             */
/*   Updated: 2021/07/15 00:05:40 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_nbr_size(size_t nbr, int base_size)
{
	int	nbr_size;

	nbr_size = 1;
	while (nbr / base_size > 0)
	{
		nbr /= base_size;
		nbr_size++;
	}
	return (nbr_size);
}

char	*ft_stoa_base(size_t nbr, const char *base)
{
	int		base_size;
	int		nbr_size;
	char	*nbr_str;

	base_size = ft_strlen(base);
	nbr_size = get_nbr_size(nbr, base_size);
	nbr_str = ft_calloc(nbr_size + 1, 1);
	if (nbr_str == NULL)
		return (NULL);
	while (nbr != 0 || nbr_size >= 1)
	{
		nbr_str[--nbr_size] = base[nbr % base_size];
		nbr /= base_size;
	}
	return (nbr_str);
}
