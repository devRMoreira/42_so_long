/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:24:10 by rimagalh          #+#    #+#             */
/*   Updated: 2024/11/02 15:50:49 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest1;
	unsigned const char	*src1;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest1 = (unsigned char *) dest;
	src1 = (unsigned char *) src;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return ((void *)dest);
}
