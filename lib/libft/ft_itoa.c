/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:37:54 by rimagalh          #+#    #+#             */
/*   Updated: 2024/11/03 00:35:07 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_count(int n)
{
	long	num;
	int		count;

	count = 0;
	num = n;
	if (n <= 0)
		count++;
	if (n < 0)
		num = -num;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	num;

	num = n;
	count = get_count(n);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count--] = '\0';
	if (n < 0)
	{
		num = -num;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[count] = (num % 10) + '0';
		num /= 10;
		count--;
	}
	return (str);
}
