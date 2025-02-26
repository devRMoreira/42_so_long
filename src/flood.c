/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:16:02 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/26 13:26:16 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void floodfill(char **map, int row, int col)
{
	if (col < 0 || row < 0 || map[row] == NULL || map[row][col] == '\0')
		return ;
	if(is_lower(map[row][col]) || map[row][col] == '1')
		return ;
	if(map[row][col] == 'f')
		return ;
	if(ft_isalpha(map[row][col]))
		map[row][col] += 32;
	if(map[row][col] == '0')
		map[row][col] = 'f';

	floodfill(map, row, col + 1);
	floodfill(map, row, col - 1);
	floodfill(map, row + 1, col);
	floodfill(map, row - 1, col );
}

int is_completable(char **map)
{
	int *coords;
	int i;
	int j;

	coords = get_player_pos(map);
	floodfill(map, coords[0], coords[1]);

	while (map[i] != NULL)
	{
		j = 0;
		while(map[i][j] != '\0')
		{
			if(map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return(1);
}
