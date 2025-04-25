/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:49:22 by juhong            #+#    #+#             */
/*   Updated: 2025/01/23 17:44:59 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_putnbr(int nb)
{
	char	temp;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
			write(1, "2147483648", 10);
		else
			ft_putnbr(-nb);
	}
	else if (nb > 0)
	{
		temp = '0' + nb % 10;
		if ((nb / 10) != 0)
			ft_putnbr(nb / 10);
		write(1, &temp, 1);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
}
