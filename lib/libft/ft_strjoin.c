/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:11:44 by rimagalh          #+#    #+#             */
/*   Updated: 2024/10/27 18:24:56 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	new = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i] != '\0')
			new[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i] != '\0')
			new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}
