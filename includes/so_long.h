/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:59:29 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/17 15:38:49 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>


typedef	struct s_data
{
	char	**map;
	void	*mlx_ptr;
	void 	*win_ptr;
	void 	*textures[5];
	int		*map_size;
	int		*player_coords;
}		t_data;

// typedef struct s_data {
// 	void *img;
// 	char *addr;
// 	int	bpp;
// 	int linelen;
// 	int endian;
// 	char	**map;
// 	int		*map_size;
// 	int		*player_coords;
// } 	t_data;

char	**parse_map(char *file);
char	**get_map(char *file);
void	free_map(char **map);
void	print_error(char *descriptor);
int		*get_player_pos(char **map);
int		valid_map(char **map);
int		valid_walls(char **map);
int		valid_chars(char **map);
int		is_lower(int c);
int		is_completable(char **map);

#endif
