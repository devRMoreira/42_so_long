/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:47:57 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/14 17:35:31 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	if(argc >= 2)
	{
		parse_map(argv[1]);
	}
	else
		ft_printf("Error\n");

}


// ! og map parse
	// int		fd;
	// int		i;
	// int		j;
	// char	*fn;
	// char	*buffer;
	// char	**map;
	// if(argc >= 2)
	// {
	// fn = ft_strjoin("./map/", argv[1]);
	// 	fd = open(fn, O_RDONLY);

	// 	if(fd < 1)
	// 		return (free(fn),ft_printf("Error \n"));

	// 	buffer = ft_get_next_line(fd);
	// 	i = 1;
	// 	j = 0;

	// 	while(buffer != NULL)
	// 	{
	// 		buffer = ft_get_next_line(fd);
	// 		i++;
	// 	}
	// 	close(fd);
	// 	free(buffer);

	// 	map = malloc(sizeof(char *) * i);
	// 	map[--i] = "\0";
	// 	fd = open(fn, O_RDONLY);
	// 	while(j < i)
	// 	{
	// 		map[j] = ft_get_next_line(fd);
	// 		j++;
	// 	}
	// 	j--;

	// 	while(j >= 0)
	// 	{
	// 		ft_printf("%s", map[j]);
	// 		j--;

	// 	}


	// } else
	// 		return ft_printf("Error \n");

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
