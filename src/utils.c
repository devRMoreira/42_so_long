/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:40:32 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/03 12:08:26 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	quit_game(t_data *game)
{
	free_game(game);
	exit(0);
	return (0);
}

static int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

static void	get_xpms(t_data *game)
{
	game->xpm[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./xpms/grnd.xpm", &game->size, &game->size);
	game->xpm[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./xpms/wall.xpm", &game->size, &game->size);
	game->xpm[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./xpms/plyr.xpm", &game->size, &game->size);
	game->xpm[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./xpms/cltb.xpm", &game->size, &game->size);
	game->xpm[4] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./xpms/exit.xpm", &game->size, &game->size);
}

void	init_struct(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (free_game(game), print_error("mlx_init"), exit(1));
	game->player = get_player_pos(game->map);
	game->total_collects = get_collects(game->map);
	game->collected = 0;
	game->moves = 0;
	game->size = SIZE;
	game->height = get_height(game->map);
	game->width = ft_strlen(game->map[0]);
	get_xpms(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->width * SIZE),
			(game->height * SIZE), "So long");
	if (!game->win_ptr)
		return (free_game(game), print_error("mlx_new_window"), exit(1));
}

void	free_game(t_data *game)
{
	int	i;

	if (game->map)
	{
		i = -1;
		while (game->map[++i] != NULL)
			free(game->map[i]);
		free(game->map);
	}
	if (game->mlx_ptr)
	{
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		i = -1;
		while (++i < 5)
			if (game->xpm[i])
				mlx_destroy_image(game->mlx_ptr, game->xpm[i]);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->player)
		free(game->player);
}
