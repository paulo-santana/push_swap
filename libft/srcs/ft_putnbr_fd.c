/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:51:20 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/25 22:33:07 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int		length;
	int		is_min;
	char	str[10];

	is_min = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		if (nb == -2147483648)
		{
			is_min = 1;
			nb++;
		}
		nb = -nb;
	}
	length = 0;
	while (nb != 0 || length < 1)
	{
		str[length] = nb % 10 + is_min + '0';
		is_min = 0;
		nb = nb / 10;
		length++;
	}
	while (--length >= 0)
		write(fd, &str[length], 1);
}
