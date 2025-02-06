/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:20:12 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/06 16:16:46 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
// ! map chars
// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.

int	valid_char(char c)
{
	char	*max;
	char	*min;
	int		i;

	max = "01CEP";
	min = "01cep";
	i = 0;
	while(max[i])
	{
		if(c == max[i] || c == min[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	i--;
	while (map[0][j])
	{
		if(map[0][j] != '1' || map[i][j] != '1')
			return (0);
		j++;
	}
	while (i >= 0)
	{
		if(map[i][0] != '1' || map[i][j] != '1' )
			return (0);
		i--;
	}
	return (1);
}
