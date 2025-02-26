/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:59:29 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/26 13:19:31 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef SIZE
#	define SIZE 64
# endif

typedef	struct s_data
{
	char	**map; //needs free
	void	*mlx_ptr; //needs free
	void 	*win_ptr; //needs free
	void 	*xpm[5]; //needs free
	int		*player; //needs free
	int		total_collects;
	int		collected;
	int		moves;
	int		lines;
	int 	cols;
}		t_data;

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
void	print_map(char **map);

#endif
