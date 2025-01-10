/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:25:43 by rimagalh          #+#    #+#             */
/*   Updated: 2024/12/10 15:53:43 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read(char *read_chars, int fd)
{
	char	*current;
	char	*temp;
	int		res;

	current = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!current)
		return (NULL);
	res = 1;
	while (res > 0)
	{
		res = read(fd, current, BUFFER_SIZE);
		if (res == -1)
			return (free(current), free(read_chars), NULL);
		current[res] = '\0';
		temp = ft_strjoin(read_chars, current);
		free(read_chars);
		read_chars = temp;
		if (ft_strchr(read_chars, '\n'))
			break ;
	}
	free(current);
	return (read_chars);
}

static char	*ft_create_line(char *read_chars)
{
	int	i;

	i = 0;
	while (read_chars[i] != '\0' && read_chars[i] != '\n')
		i++;
	if (read_chars[i] == '\n')
		i++;
	return (ft_substr(read_chars, 0, i));
}

static char	*ft_clean_chars(char *read_chars)
{
	char	*new_chars;
	int		i;

	i = 0;
	while (read_chars[i] != '\0' && read_chars[i] != '\n')
		i++;
	if (!read_chars[i])
	{
		free(read_chars);
		return (NULL);
	}
	new_chars = ft_strdup(read_chars + i + 1);
	free(read_chars);
	return (new_chars);
}

char	*ft_get_next_line(int fd)
{
	static char	*read_chars;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_chars)
		read_chars = ft_strdup("");
	if (!ft_strchr(read_chars, '\n'))
		read_chars = ft_read(read_chars, fd);
	if (!read_chars || *read_chars == '\0')
	{
		free(read_chars);
		read_chars = NULL;
		return (NULL);
	}
	line = ft_create_line(read_chars);
	read_chars = ft_clean_chars(read_chars);
	return (line);
}
