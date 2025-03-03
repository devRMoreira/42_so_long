/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:47:57 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/03 11:10:06 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data game;

	if (argc == 2)
	{
		game.map = parse_map(argv[1]);
		if (!game.map)
			return (free_game(&game), 1);
	}
	else
		return (print_error("Missing path/to/map"), 1);

	init_struct(&game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &quit_game, &game);
	render_game(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
