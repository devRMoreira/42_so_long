/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:35:38 by rimagalh          #+#    #+#             */
/*   Updated: 2024/11/04 19:16:58 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	sep;
	int	words;

	i = 0;
	sep = 1;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && sep == 1)
		{
			words++;
			sep = 0;
		}
		if (s[i] == c && sep == 0)
			sep = 1;
		i++;
	}
	return (words);
}

static int	ft_skip(char const *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

static char	**ft_memfree(char **s, int q)
{
	int	i;

	i = 0;
	while (i <= q)
		free(s[i++]);
	free(s);
	return (NULL);
}

static int	ft_strings(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		i = ft_skip(s, c, i);
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > j)
		{
			arr[k] = ft_substr(s, j, i - j);
			if (!arr[k])
				return (k);
			k++;
		}
	}
	arr[k] = NULL;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	int		res;
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	res = ft_strings(arr, s, c);
	if (res != -1)
		return (ft_memfree(arr, res));
	return (arr);
}
