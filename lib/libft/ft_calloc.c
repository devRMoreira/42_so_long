/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:54:07 by rimagalh          #+#    #+#             */
/*   Updated: 2024/11/02 21:34:11 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	valid_size(size_t nmemb, size_t size)
{
	size_t	max_size;

	max_size = (size_t)-1;
	if (nmemb > (max_size / size))
		return (0);
	else
		return (nmemb * size);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total;

	if (!nmemb || !size)
		total = 0;
	else
		total = valid_size(nmemb, size);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
