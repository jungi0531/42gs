/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <juhong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:59:04 by juhong            #+#    #+#             */
/*   Updated: 2025/05/01 14:49:26 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		ft_print_char(va_arg(args, int), &count);
	else if (type == 's')
		ft_print_str(va_arg(args, char *), &count);
	else if (type == 'p')
		ft_print_ptr((uintptr_t)va_arg(args, void *), &count);
	else if (type == 'd' || type == 'i')
		ft_print_nbr(va_arg(args, int), &count);
	else if (type == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), &count);
	else if (type == 'x')
		ft_print_hex(va_arg(args, unsigned int), 0, &count);
	else if (type == 'X')
		ft_print_hex(va_arg(args, unsigned int), 1, &count);
	else if (type == '%')
		ft_print_char('%', &count);
	else
		return (-1);
	return (count);
}
