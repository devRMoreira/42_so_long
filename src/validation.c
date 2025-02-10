/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:20:15 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/10 14:18:30 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int valid_size(char **map)
{
	unsigned int size;
	int i;

	size = ft_strlen(map[0]);
	if(size < 3)
		return (0);
	i = 0;
	while(map[i] != NULL)
	{
		if(ft_strlen(map[i]) != size)
			return (0);
		i++;
	}
	return (1);
}



int	valid_map(char **map)
{
	if(!map)
		return (0);
	if(!valid_size(map))
		return (print_error("Invalid line size"), 0);
	if(!valid_walls(map))
		return (print_error("Invalid walls"), 0);
	if(!valid_chars(map))
		return (0);
	return (1);
}
