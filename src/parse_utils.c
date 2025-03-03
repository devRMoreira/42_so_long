/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:41:42 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/10 11:41:42 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static char	*fetch_line(int fd)
{
	char	*nl_pos;
	char	*temp;

	temp = ft_get_next_line(fd);
	if (temp)
	{
		nl_pos = ft_strchr(temp, '\n');
		if (nl_pos)
			*nl_pos = '\0';
	}
	return (temp);
}

static int	get_total_lines(char *file)
{
	int		fd;
	int		i;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	temp = ft_get_next_line(fd);
	i = 1;
	while (temp != NULL)
	{
		free(temp);
		temp = ft_get_next_line(fd);
		i++;
	}
	close(fd);
	free(temp);
	return (i);
}

char	**get_map(char *file)
{
	int		i;
	int		fd;
	int		lines;
	char	**map;

	lines = get_total_lines(file);
	if (lines < 3)
		return (print_error("Invalid map"), NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (print_error("Malloc failure"), NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("Invalid file"), NULL);
	i = -1;
	while (++i < lines)
		map[i] = fetch_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}
