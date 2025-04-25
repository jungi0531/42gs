/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:59:22 by juhong            #+#    #+#             */
/*   Updated: 2025/02/02 20:19:42 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

void	make_size_flag(int grid[SIZE][SIZE], int view[4][SIZE]);
void	make_one_flag(int grid[SIZE][SIZE], int view[4][SIZE], int i);
void	put_flag_col(int grid[SIZE][SIZE], int x, int rv);
void	put_flag_row(int grid[SIZE][SIZE], int y, int rv);

void	make_size_flag(int grid[SIZE][SIZE], int view[4][SIZE])
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (view[0][i] == SIZE)
			put_flag_col(grid, i, 0);
		if (view[1][i] == SIZE)
			put_flag_col(grid, i, 1);
		if (view[2][i] == SIZE)
			put_flag_row(grid, i, 0);
		if (view[3][i] == SIZE)
			put_flag_row(grid, i, 1);
		i++;
	}
}

void	make_one_flag(int grid[SIZE][SIZE], int view[4][SIZE], int i)
{
	i = 0;
	while (i < SIZE)
	{
		if (view[0][i] == 1)
		{
			grid[0][i] = SIZE;
			grid[0 + SIZE][i] = 1;
		}
		if (view[1][i] == 1)
		{
			grid[SIZE - 1][i] = SIZE;
			grid[SIZE - 1 + SIZE][i] = 1;
		}
		if (view[2][i] == 1)
		{
			grid[i][0] = SIZE;
			grid[i + SIZE][0] = 1;
		}
		if (view[3][i] == 1)
		{
			grid[i][SIZE - 1] = SIZE;
			grid[i + SIZE][SIZE - 1] = 1;
		}
		i++;
	}
}

void	put_flag_col(int grid[SIZE][SIZE], int x, int rv)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (rv)
		{
			grid[SIZE - i - 1][x] = i + 1;
			grid[SIZE - i - 1 + SIZE][x] = 1;
		}
		else
		{
			grid[i][x] = i + 1;
			grid[i + SIZE][x] = 1;
		}
		i++;
	}
}

void	put_flag_row(int grid[SIZE][SIZE], int y, int rv)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (rv)
		{
			grid[y][SIZE - i - 1] = i + 1;
			grid[y + SIZE][SIZE - i - 1] = 1;
		}
		else
		{
			grid[y][i] = i + 1;
			grid[y + SIZE][i] = 1;
		}
		i++;
	}
}
