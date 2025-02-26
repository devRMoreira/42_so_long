/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:36:05 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/26 13:30:42 by rimagalh         ###   ########.fr       */
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
			if(map[row][col] == 'P' || map[row][col] == 'p')
			{
				coords[0] = row;
				coords[1] = col;
				break;
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
