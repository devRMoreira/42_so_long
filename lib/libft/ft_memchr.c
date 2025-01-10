/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:01:19 by rimagalh          #+#    #+#             */
/*   Updated: 2024/10/28 18:56:56 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*src;
	size_t				i;

	i = 0;
	src = s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void *) src + i);
		i++;
	}
	return (NULL);
}
