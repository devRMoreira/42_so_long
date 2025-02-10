/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:15:09 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/10 14:13:34 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**parse_map(char *file)
{
	char	**map;

	map = get_map(file);
	if (!valid_map(map))
		return (free_map(map), NULL);
	return (map);
}
