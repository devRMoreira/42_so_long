/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:44:03 by rimagalh          #+#    #+#             */
/*   Updated: 2024/11/04 12:49:43 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i] == (unsigned char) c)
		return (str + i);
	while (i >= 0)
	{
		if (str[i] == (unsigned char) c)
			return (str + i);
		i--;
	}
	return (NULL);
}
