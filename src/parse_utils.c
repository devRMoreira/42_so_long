/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:21:48 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/14 17:21:48 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

int	get_total_lines(char *fn)
{
	int		fd;
	int		i;
	char	*buffer;

	i = 1;
	fd = open(fn, O_RDONLY);
	if (fd < 1)
		return (-1);
	buffer = ft_get_next_line(fd);
	while (buffer != NULL)
	{
		buffer = ft_get_next_line(fd);
		i++;
	}
	close(fd);
	free(buffer);
	return (i);
}

char	**get_map(char *file)
{
	int		fd;
	int		size;
	int		i;
	char	**map;
	char	*temp;

	size = get_total_lines(file);
	if (size == -1)
		return (NULL);
	map = malloc(sizeof(char *) * size + 1);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	map[size + 1] = NULL;
	i = 0;
	while (i < size)
	{
		temp = ft_get_next_line(fd);
		ft_strlcat(map[i], temp, ft_strlen(temp) - 1);
		free(temp);
		i++;
	}
	return (map);
}
