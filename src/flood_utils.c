/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:36:05 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/13 15:05:48 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int *get_player_pos(char **map)
{
	int row;
	int col;
	int *coords;

	coords = malloc(sizeof(int) * 2);
	row = 0;
	while(map[row])
	{
		col = 0;
		while(map[row][col])
		{
			if(map[row][col] == 'P')
			{
				coords[0] = col;
				coords[1] = row;
			}
			col++;
		}
		row++;
	}
	return (coords);
}

int	is_lower(int c)
{
	return (c >= 'a' && c <= 'z');
}
// char **copy_map(char **map)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	j = 0;


// }
