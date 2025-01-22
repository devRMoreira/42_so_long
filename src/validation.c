/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:20:15 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/22 18:49:10 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	valid_cells(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[i])
	{
		while (map[i][j] != '\0')
		{
			if(!valid_char(map[i][j]))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}


	return (1);
}

static int	valid_size(char **map)
{
	int				i;
	unsigned int	line_size;

	i = 1;
	line_size = ft_strlen(map[0]);
	if (!line_size || line_size < 3)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != line_size)
			return (0);
		i++;
	}
	return (1);
}

int	valid_map(char **map)
{
	int	res;

	res = valid_size(map);
	if (!res)
		return (0);
	res = valid_cells(map);
	if (!res)
		return (0);
	return (1);
}
