/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:59:29 by rimagalh          #+#    #+#             */
/*   Updated: 2025/03/03 13:37:41 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef SIZE
#  define SIZE 64
# endif

typedef struct s_data
{
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*xpm[5];
	int		*player;
	int		total_collects;
	int		collected;
	int		moves;
	int		height;
	int		width;
	int		size;
}		t_data;

int		quit_game(t_data *game);
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
int		keypress(int key, t_data *game);
int		get_collects(char **map);
void	render_game(t_data *game);
void	move_handler(int col_offset, int row_offset, t_data *game);
void	init_struct(t_data *game);
void	free_game(t_data *game);

#endif
