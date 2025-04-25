/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:58:12 by juhong            #+#    #+#             */
/*   Updated: 2025/02/03 16:34:02 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_ten_queens_puzzle(void);
int		backtracking(int row[10], int ncol, int *count);
int		is_valid(int row[10], int ncol, int num);
void	print_board(int row[10]);

#ifdef TEST

int	main(void)
{
	return (0);
}

#endif

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	row[10];
	int	ncol;
	int	count;

	count = 0;
	ncol = 0;
	i = 0;
	while (i < 10)
	{
		row[i] = 0;
		i++;
	}
	backtracking(row, ncol, &count);
	return (count);
}

int	backtracking(int row[10], int ncol, int *count)
{
	int	i;
	int	num;

	if (ncol == 10)
	{
		print_board(row);
		(*count)++;
		return (0);
	}
	i = 0;
	num = 0;
	while (num < 10)
	{
		if (is_valid(row, ncol, num))
		{
			row[ncol] = num;
			backtracking(row, ncol + 1, count);
			row[ncol] = 0;
		}
		num++;
	}
	return (0);
}

int	is_valid(int row[10], int ncol, int num)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	while (i < ncol)
	{
		if (row[i] == num)
			return (0);
		if (i > ncol)
			a = i - ncol;
		else
			a = ncol - i;
		if (row[i] > num)
			b = row[i] - num;
		else
			b = num - row[i];
		if (a == b)
			return (0);
		i++;
	}
	return (1);
}

void	print_board(int row[10])
{
	int		i;
	char	temp;

	i = 0;
	while (i < 10)
	{
		temp = row[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	write(1, "\n", 1);
}
