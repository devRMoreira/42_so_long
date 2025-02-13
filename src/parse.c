/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:15:09 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/13 12:14:47 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int valid_file(char *file)
{
	unsigned int size;
	int i;

	size = ft_strlen(file);
	if(size < 5)
		return (0);
	if(!ft_strnstr(file, ".ber", size))
		return (0);
	i = size;
	while(file[--i])
	{
		if(file[i] == '.')
			break;
	}
	if(file[i - 1] == '/' || file[i + 4] != '\0')
		return (0);
	return (1);
}

char	**parse_map(char *file)
{
	char	**map;

	if(!valid_file(file))
		return (print_error("Invalid file name"), NULL);
	map = get_map(file);
	if (!valid_map(map))
		return (free_map(map), NULL);
	is_completable(map);
	return (map);
}
