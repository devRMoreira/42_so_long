/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:47:57 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/25 12:34:17 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

void print_map(char **map) {
    int i = 0;
    while (map[i]) {
        printf("%s\n", map[i]);
        i++;
    }
}


void print_player_coords(int *player_coords) {
    if (player_coords != NULL) {
        printf("Player coordinates: (row %d, col %d)\n", player_coords[0], player_coords[1]);
    } else {
        printf("Player coordinates not found.\n");
    }
}

void	print_error(char *descriptor)
{
	ft_printf("Error\n%s\n", descriptor);
}

int quit_game(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
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
		game->map[game->player[0]][game->player[1]] = 'f';
		game->map[new_row][new_col] = 'P';
	}

	print_map(game->map);
}

void player_move(char c, t_data *game)
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
	ft_printf("pressed: %d\n", key);

	if (key == XK_Left)
		player_move('l', game);

	if (key == XK_Up)
		player_move('u', game);

	if (key == XK_Right)
		player_move('r', game);

	if (key == XK_Down)
		player_move('d', game);

	if (key == XK_Escape)
		quit_game(game);

	return (0);
}

int	main(int argc, char **argv)
{
	t_data game;

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);

	if (argc >= 2)
	{
		game.map = parse_map(argv[1]);
		if (!game.map)
			return (1);

		//! returns map with all lower, missing flood fix
		game.player = get_player_pos(game.map);
		print_player_coords(game.player);
	}
	else
		return (print_error("Missing argument"), 1);

	game.win_ptr = mlx_new_window(game.mlx_ptr, 600, 400, "Window Name");

	if(!game.win_ptr)
		return (free(game.mlx_ptr), 1);

	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, quit_game, &game);

	mlx_loop(game.mlx_ptr);
	return (0);
}
