/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_base.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:41:20 by rimagalh          #+#    #+#             */
/*   Updated: 2024/11/11 09:41:45 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkbase(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (base[i] == base[i + 1])
			return (1);
		i++;
	}
	if (i == 1)
		return (1);
	if (i == 10 || i == 2 || i == 16 || i == 8)
		return (i);
	return (1);
}

void	ft_putnbr_unsigned_base(unsigned long nbr, char *base)
{
	unsigned long	nb;
	unsigned int	i;

	i = 0;
	nb = nbr;
	if (checkbase(base) == 1)
		return ;
	while (base[i])
		i++;
	if (nb >= i)
	{
		ft_putnbr_unsigned_base(nb / i, base);
		ft_putnbr_unsigned_base(nb % i, base);
	}
	else
		ft_putchar_fd(base[nb], 1);
}
