/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:37:23 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/03 12:01:56 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	get_xpm_id(char c)
{
	if (c == '0' || c == 'f')
		return (0);
	if (c == '1')
		return (1);
	if (c == 'p' || c == 'P')
		return (2);
	if (c == 'c' || c == 'C')
		return (3);
	if (c == 'e' || c == 'E')
		return (4);
	return (-1);
}

void	render_game(t_data *game)
{
	int	col;
	int	row;
	int	id;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			id = get_xpm_id(game->map[row][col]);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->xpm[id],
				col * game->size, row * game-> size);
			col++;
		}
		row++;
	}
}
