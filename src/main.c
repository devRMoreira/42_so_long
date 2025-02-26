/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:47:57 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/26 13:46:47 by rimagalh         ###   ########.fr       */
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

void init_struct(t_data *game)
{
	game->player = get_player_pos(game->map);
	game->total_collects = get_collects(game->map);
	game->collected = 0;
	game->moves = 0;
	game->lines = 0;
	game->cols = 0;
}

void print_player_coords(int *player_coords) {
    if (player_coords != NULL) {
        ft_printf("Player coordinates: (row %d, col %d)\n", player_coords[0], player_coords[1]);
    } else {
        ft_printf("Player coordinates not found.\n");
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

void handle_exit(t_data *game)
{
	if(game->collected == game->total_collects)
	{
		ft_printf("You got all collectables!\n");
		quit_game(game);
	}
	else
		ft_printf("You're still missing %d collectables!\n", game->total_collects - game->collected);
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
		game->player[0] = new_row;
		game->player[1] = new_col;
		game->moves += 1;
		ft_printf("%d moves\n",game->moves);

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

int	main(int argc, char **argv)
{
	t_data game;

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (print_error("mlx_init"), 1);
	if (argc >= 2)
	{

		game.map = parse_map(argv[1]);
		if (!game.map)
		return (1);

		init_struct(&game);
		//! returns map with all lower
		print_player_coords(game.player);
	}
	else
		return (print_error("Missing path/to/map"), 1);

	game.win_ptr = mlx_new_window(game.mlx_ptr, 600, 400, "Window Name");

	if(!game.win_ptr)
		return (free(game.mlx_ptr), 1);

	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, quit_game, &game);

	mlx_loop(game.mlx_ptr);
	return (0);
}
