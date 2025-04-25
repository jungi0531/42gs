/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:47:45 by juhong            #+#    #+#             */
/*   Updated: 2025/02/11 21:27:14 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		num1;
	int		num2;
	char	temp[2];

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			temp[0] = '0' + num1 / 10;
			temp[1] = '0' + num1 % 10;
			write(1, temp, 2);
			write(1, " ", 1);
			temp[0] = '0' + num2 / 10;
			temp[1] = '0' + num2 % 10;
			write(1, temp, 2);
			if (!(num1 == 98 && num2 == 99))
				write(1, ", ", 2);
			num2++;
		}
		num1++;
	}
}

#ifdef TEST

int	main(void)
{
	ft_print_comb2();
	return (0);
}

#endif
