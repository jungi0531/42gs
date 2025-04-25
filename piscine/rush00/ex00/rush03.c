/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:56:27 by juhong            #+#    #+#             */
/*   Updated: 2025/01/25 17:42:42 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	print_coor(int x, int y, int width, int length);
void	rush00(int x, int y);
int		error_handling(int x, int y);

void	rush00(int x, int y)
{
	int	width;
	int	length;

	if (error_handling(x, y))
		return ;
	length = 0;
	while (length < y)
	{
		width = 0;
		while (width < x)
		{
			print_coor(x, y, width, length);
			width++;
		}
		write(1, "\n", 1);
		length++;
	}
}

void	print_coor(int x, int y, int width, int length)
{
	if (width == 0)
	{
		if (length == 0 || length == y - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else if (width == x - 1)
	{
		if (length == 0 || length == y - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (length == 0 || length == y - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

int	error_handling(int x, int y)
{
	if (x < 0 || y < 0)
		return (1);
	return (0);
}
