/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:47:57 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/17 21:37:04 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int keypress(int keysym, t_data *game)
{

	ft_printf("Pressed key: %d\n", keysym);

	if (keysym == 65361) //left
		// player_move();

	if (keysym == 65362) //up
		// player_move();

	if (keysym == 65363) //right
		// player_move();

	if (keysym == 65364) //down
		// player_move();

	if (keysym == 65307) //ESC
		// quit_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data game;

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);

	// if (argc >= 2)
	// {
	// 	game.map = parse_map(argv[1]);
	// 	if (!game.map)
	// 		return (1);
	// }
	// else
	// 	return (print_error("Missing argument"), 1);

	game.win_ptr = mlx_new_window(game.mlx_ptr, 600, 400, "Window Name");

	if(!game.win_ptr)
		return (free(game.mlx_ptr), 1);

	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &quit_game, &game);

	mlx_loop(game.mlx_ptr);
	return (0);
}

// ! mlx docs main
// typedef struct s_data {
// 	void *img;
// 	char *addr;
// 	int	bpp;
// 	int linelen;
// 	int endian;
// } 	t_data;

// void pxlput(t_data *data, int x, int y, int color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->linelen + x * (data->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

// int main(void)
// {
// 	t_data img;
// 	void *mlx;
// 	void *mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1280, 720, "sds");
// 	img.img = mlx_new_image(mlx, 1280, 720);
// 	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.linelen, &img.endian);
// 	pxlput(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);

// }
