/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:20:12 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/22 18:41:04 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_char(char c)
{
	if (c == '0')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == 'C')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'P')
		return (1);
	else
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
