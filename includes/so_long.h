/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:59:29 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/14 17:36:26 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"

int parse_map(char *file);
int get_total_lines(char* fn);
char **get_map(char *file);

#endif
