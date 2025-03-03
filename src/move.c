/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:39:43 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/03 10:47:21 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void handle_exit(t_data *game)
{
	if(game->collected == game->total_collects)
	{
		ft_printf("You got all collectables!\n");
		quit_game(game);
	}
	else
		ft_printf("You're still missing %d collectables!\n", game->total_collects - game->collected);
}

static void player_move(char c, t_data *game)
{
	if (c == 'l')
		move_handler(0, -1, game);
	if (c == 'u')
		move_handler(-1, 0, game);
	if (c == 'r')
		move_handler(0, 1, game);
	if (c == 'd')
		move_handler(1, 0, game);
}

int keypress(int key, t_data *game)
{
	if (key == XK_a || key == XK_Left)
		player_move('l', game);

	if (key == XK_w || key == XK_Up)
		player_move('u', game);

	if (key == XK_d || key == XK_Right)
		player_move('r', game);

	if (key == XK_s || key == XK_Down)
		player_move('d', game);

	if (key == XK_Escape)
		quit_game(game);

	return (0);
}

void move_handler(int col_offset, int row_offset, t_data *game)
{
	int new_col;
	int new_row;

	new_row = game->player[0] + col_offset;
	new_col = game->player[1] + row_offset;

	if(game->map[new_row][new_col] != '1')
	{
		if(game->map[new_row][new_col] == 'c')
		{
			game->collected += 1;
			ft_printf("Collected %d out of %d\n",game->collected, game->total_collects);
		}
		if(game->map[new_row][new_col] == 'e')
			handle_exit(game);
		game->map[game->player[0]][game->player[1]] = '0';
		game->map[new_row][new_col] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->xpm[0], game->player[1] * game->size, game->player[0] * game-> size);

		game->player[0] = new_row;
		game->player[1] = new_col;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->xpm[2], new_col * game->size, new_row * game-> size);
		game->moves += 1;
		ft_printf("%d moves\n",game->moves);

	}
}
