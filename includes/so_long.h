/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:59:29 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/10 14:12:27 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"

char	**parse_map(char *file);
char	**get_map(char *file);
void	free_map(char **map);
void	print_error(char *descriptor);
int		valid_map(char **map);
int		valid_walls(char **map);
int		valid_chars(char **map);


#endif
