/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_input_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:42:57 by rimagalh          #+#    #+#             */
/*   Updated: 2024/12/10 15:38:22 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_input_type(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 'd')
		return (4);
	if (c == 'i')
		return (5);
	if (c == 'u')
		return (6);
	if (c == 'x')
		return (7);
	if (c == 'X')
		return (8);
	if (c == '%')
		return (9);
	return (0);
}

int	ft_input_convert(int type, va_list args)
{
	if (type == 1)
		return (ft_output_single(1, args));
	if (type == 2)
		return (ft_output_long(2, args));
	if (type == 3)
		return (ft_output_long(3, args));
	if (type == 4)
		return (ft_output_long(4, args));
	if (type == 5)
		return (ft_output_long(5, args));
	if (type == 6)
		return (ft_output_long(6, args));
	if (type == 7)
		return (ft_output_long(7, args));
	if (type == 8)
		return (ft_output_long(8, args));
	if (type == 9)
		return (ft_output_single(9, args));
	return (0);
}
