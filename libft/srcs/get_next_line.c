/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:38:38 by psergio-          #+#    #+#             */
/*   Updated: 2021/12/05 15:38:38 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#define FD_MAX 256

void	move_buffer(char *buffer, int amount)
{
	ft_memmove(buffer, buffer + amount, BUFFER_SIZE - amount + 1);
}

int	get_more_text(char *buffer, int fd)
{
	int	result;

	result = read(fd, buffer, BUFFER_SIZE);
	buffer[result] = '\0';
	return (result);
}

int	merge_strings(char **new_str, char *tail, int size)
{
	char	*tmp;
	char	*tail_str;

	tail_str = ft_substr(tail, 0, size);
	if (tail_str == NULL)
		return (-1);
	if (*new_str)
	{
		tmp = ft_strjoin(*new_str, tail_str);
		free(tail_str);
	}
	else
		tmp = tail_str;
	free(*new_str);
	*new_str = tmp;
	return (1);
}

int	get_newline(char *buffer, char **new_str, int fd)
{
	int	result;
	int	i;

	i = 0;
	while (1)
	{
		if (buffer[i] == '\0')
		{
			merge_strings(new_str, buffer, i);
			result = get_more_text(buffer, fd);
			if (result < 1)
				break ;
			i = 0;
		}
		if (buffer[i] == '\n')
		{
			merge_strings(new_str, buffer, i);
			move_buffer(buffer, i + 1);
			return (GNL_LINE_READ);
		}
		i++;
	}
	return (result);
}

int	get_next_line(int fd, char **line)
{
	int			result;
	char		*newstr;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > FD_MAX)
		return (GNL_ERROR);
	result = GNL_NO_NEWLINE;
	newstr = NULL;
	while (result == GNL_NO_NEWLINE)
	{
		result = get_newline(buffer, &newstr, fd);
		if (result == -1)
		{
			free(newstr);
			newstr = NULL;
		}
	}
	*line = newstr;
	return (result);
}
