/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:56:38 by juhong            #+#    #+#             */
/*   Updated: 2025/02/11 21:56:52 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	ft_print_comb(void)
{
	char	num[3];

	num[0] = '0';
	while (num[0] <= '7')
	{
		num[1] = num[0] + 1;
		while (num[1] <= '8')
		{
			num[2] = num[1] + 1;
			while (num[2] <= '9')
			{
				write(1, num, 3);
				if (!(num[0] == '7' && num[1] == '8' && num[2] == '9'))
					write(1, ", ", 2);
				num[2]++;
			}
			num[1]++;
		}
		num[0]++;
	}
}

#ifdef TEST

int	main(void)
{
	ft_print_comb();
	return (0);
}

#endif
