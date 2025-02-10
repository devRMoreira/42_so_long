/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:20:12 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/10 14:17:34 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
// ! map chars
// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.
static void uppercase(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

static int check_char(char c)
{
	if(c == 'C')
		return (0);
	if(c == 'E')
		return (1);
	if(c == 'P')
		return (2);
	return (-1);
}

static int *count_chars(char **map)
{
	int i;
	int j;
	char	*chars;
	int		*amount;

	amount = ft_calloc(3, sizeof(int));
	chars = "01CEP";
	i = -1;
	while(map[++i])
	{
		j = 0;
		while(map[i][j])
		{
			if(check_char(map[i][j]) != -1)
			{
				if(!amount[check_char(map[i][j])])
					amount[check_char(map[i][j])] = 1;
				else
					amount[check_char(map[i][j])]++;
			}
			j++;
		}
	}
	return (amount);
}

int valid_chars(char **map)
{
	int i;
	int *amount;
	i = -1;
	while(map[++i])
		ft_striteri(map[i], uppercase);
	amount = count_chars(map);
	if(amount[0] < 1)
		return (print_error("Invalid collectable amount"), free(amount), 0);
	if(amount[1] != 1)
		return (print_error("Invalid exit amount"), free(amount), 0);
	if(amount[2] != 1)
		return (print_error("Invalid player amount"), free(amount), 0);
	free(amount);
	return (1);
}

int	valid_walls(char **map)
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
	j--;
	while (i >= 0)
	{
		if(map[i][0] != '1' || map[i][j] != '1' )
			return (0);
		i--;
	}
	return (1);
}
