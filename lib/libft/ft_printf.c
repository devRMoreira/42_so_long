/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:49:18 by rimagalh          #+#    #+#             */
/*   Updated: 2024/12/10 15:38:51 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		counter;

	va_start(args, input);
	counter = ft_input_handler(input, args);
	va_end(args);
	return (counter);
}
