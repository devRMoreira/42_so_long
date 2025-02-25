/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:16:02 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/25 12:18:54 by rimagalh         ###   ########.fr       */
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

	floodfill(map, col + 1, row);
	floodfill(map, col - 1, row);
	floodfill(map, col, row + 1);
	floodfill(map, col, row - 1);
}

int is_completable(char **map)
{
	int *coords;

	coords = get_player_pos(map);
	floodfill(map, coords[0], coords[1]);

	//! missing completion check -> collectables and exit
	return(0);
}
