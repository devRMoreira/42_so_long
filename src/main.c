/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:47:57 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/03 12:08:21 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(char *descriptor)
{
	ft_printf("Error\n%s\n", descriptor);
}

int	main(int argc, char **argv)
{
	t_data	game;

	ft_memset(&game, 0, sizeof(t_data));
	if (argc == 2)
	{
		game.map = parse_map(argv[1]);
		if (!game.map)
			return (free_game(&game), 1);
	}
	else
		return (print_error("Invalid arguments"), 1);
	init_struct(&game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify,
		StructureNotifyMask, &quit_game, &game);
	render_game(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
