/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:47:44 by rimagalh          #+#    #+#             */
/*   Updated: 2024/12/10 15:38:42 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_input_handler(const char *input, va_list args)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (input[i] != '\0')
	{
		if (input[i] != '%')
		{
			ft_putchar_fd(input[i], 1);
			counter++;
			i++;
		}
		else if (input[i] == '%')
		{
			if (ft_input_type(input[i + 1]))
			{
				counter += ft_input_convert(ft_input_type(input[i + 1]), args);
				i += 2;
			}
			else
				i++;
		}
	}
	return (counter);
}
