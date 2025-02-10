/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:47:57 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/10 14:22:37 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(char *descriptor)
{
	ft_printf("Error\n%s\n", descriptor);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc >= 2)
	{
		map = parse_map(argv[1]);
		if (!map)
			return (1);
	}
	else
		return (print_error("Missing argument"), 1);
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
