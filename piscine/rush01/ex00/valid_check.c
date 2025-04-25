/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:45:53 by juhong            #+#    #+#             */
/*   Updated: 2025/02/02 20:19:46 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 4

int	is_valid_coor(int grid[SIZE][SIZE], int x, int y, int num);
int	is_valid_view(int grid[SIZE][SIZE], int view[4][SIZE]);
int	is_valid_row_view(int grid[SIZE][SIZE], int y, int view_num, int rv);
int	is_valid_col_view(int grid[SIZE][SIZE], int x, int view_num, int rv);
int	compare_max(int *max, int num, int count);

int	is_valid_coor(int grid[SIZE][SIZE], int x, int y, int num)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[y][i] == num || grid[i][x] == num)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_view(int grid[SIZE][SIZE], int view[4][SIZE])
{
	int	x;
	int	y;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			if (is_valid_col_view(grid, x, view[0][x], 0) == 0)
				return (0);
			if (is_valid_col_view(grid, x, view[1][x], 1) == 0)
				return (0);
			if (is_valid_row_view(grid, y, view[2][y], 0) == 0)
				return (0);
			if (is_valid_row_view(grid, y, view[3][y], 1) == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_valid_row_view(int grid[SIZE][SIZE], int y, int view_num, int rv)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	max = 0;
	while (i < SIZE)
	{
		if (rv)
			count = compare_max(&max, grid[y][SIZE - i - 1], count);
		else
			count = compare_max(&max, grid[y][i], count);
		i++;
	}
	if (count != view_num)
		return (0);
	return (1);
}

int	is_valid_col_view(int grid[SIZE][SIZE], int x, int view_num, int rv)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	max = 0;
	while (i < SIZE)
	{
		if (rv)
			count = compare_max(&max, grid[SIZE - i - 1][x], count);
		else
			count = compare_max(&max, grid[i][x], count);
		i++;
	}
	if (count != view_num)
		return (0);
	return (1);
}

int	compare_max(int *max, int num, int count)
{
	if (*max < num)
	{
		*max = num;
		count++;
	}
	return (count);
}
