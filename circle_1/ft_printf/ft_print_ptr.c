/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <juhong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:55:23 by juhong            #+#    #+#             */
/*   Updated: 2025/05/01 14:59:21 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(uintptr_t ptr, int *count)
{
	char	*base;
	char	buffer[20];
	int		i;

	base = "0123456789abcdef";
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*count) += 2;
	i = 0;
	while (ptr > 0)
	{
		buffer[i++] = base[ptr % 16];
		ptr /= 16;
	}
	while (i--)
		ft_print_char(buffer[i], count);
}
