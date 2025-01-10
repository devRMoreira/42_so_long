/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:48:13 by rimagalh          #+#    #+#             */
/*   Updated: 2024/12/10 15:38:48 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n, char *base)
{
	int	div;
	int	counter;

	div = ft_strlen(base);
	if (n == 0)
		return (ft_putstr("0"));
	counter = 0;
	if (n < 0)
		counter++;
	ft_putnbr_base(n, base);
	while (n != 0)
	{
		n /= div;
		counter++;
	}
	return (counter);
}

int	ft_putnbr_unsigned(unsigned long n, char *base)
{
	int	div;
	int	counter;

	div = ft_strlen(base);
	if (n == 0)
		return (ft_putstr("0"));
	counter = 0;
	ft_putnbr_unsigned_base(n, base);
	while (n != 0)
	{
		n /= div;
		counter++;
	}
	return (counter);
}

int	ft_putptr(void *ptr)
{
	int	counter;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	counter = ft_putstr("0x");
	counter += ft_putnbr_unsigned((unsigned long)ptr, "0123456789abcdef");
	return (counter);
}
