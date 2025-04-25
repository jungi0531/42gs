/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:19:35 by juhong            #+#    #+#             */
/*   Updated: 2025/01/29 22:42:16 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	temp;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		temp = (nb % 10) + '0';
		if (nb / 10 != 0)
			ft_putnbr(nb / 10);
		write(1, &temp, 1);
	}
}

#ifdef TEST

int	main(void)
{
	return (0);
}

#endif
