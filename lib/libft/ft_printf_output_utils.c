/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:04:16 by rimagalh          #+#    #+#             */
/*   Updated: 2024/12/10 15:38:45 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_output_single(int type, va_list args)
{
	if (type == 1)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	if (type == 9)
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_output_long(int type, va_list args)
{
	if (type == 2)
		return (ft_putstr(va_arg(args, char *)));
	if (type == 3)
		return (ft_putptr(va_arg(args, void *)));
	if (type == 4)
		return (ft_putnbr((long)va_arg(args, int), "0123456789"));
	if (type == 5)
		return (ft_putnbr((long)va_arg(args, int), "0123456789"));
	if (type == 6)
		return (ft_putnbr_unsigned((unsigned long)va_arg(args, unsigned int),
				"0123456789"));
	if (type == 7)
		return (ft_putnbr_unsigned((unsigned long)va_arg(args, unsigned int),
				"0123456789abcdef"));
	if (type == 8)
		return (ft_putnbr_unsigned((unsigned long)va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	return (0);
}
