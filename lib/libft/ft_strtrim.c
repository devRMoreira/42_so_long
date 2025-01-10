/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:13:00 by rimagalh          #+#    #+#             */
/*   Updated: 2024/10/27 22:35:43 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	included(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && included(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && included(s1[end - 1], set))
		end--;
	new = malloc(sizeof(char) * (end - start + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (start < end)
	{
		new[i] = s1[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
