/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 03:38:48 by psergio-          #+#    #+#             */
/*   Updated: 2021/07/27 03:38:48 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

size_t	ft_umin(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}
