/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Huiseung Gim <hsgim7979@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:54:36 by juhong            #+#    #+#             */
/*   Updated: 2025/02/02 20:19:39 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define SIZE 4

void	make_size_flag(int grid[SIZE][SIZE], int view[4][SIZE]);
void	make_one_flag(int grid[SIZE][SIZE], int view[4][SIZE], int i);

int		is_valid_coor(int grid[SIZE][SIZE], int x, int y, int num);
int		is_valid_view(int grid[SIZE][SIZE], int view[4][SIZE]);
int		is_valid_row_view(int grid[SIZE][SIZE], int y, int view_num, int rv);
int		is_valid_col_view(int grid[SIZE][SIZE], int x, int view_num, int rv);

void	init_grid(int grid[SIZE][SIZE]);
int		init_view(int view[4][SIZE], char *argv);
int		backtracking(int grid[SIZE][SIZE], int x, int y, int view[4][SIZE]);
void	print_board(int grid[SIZE][SIZE]);
int		parse_view(const char *input, int view[4][SIZE]);

int	main(int argc, char *argv[])
{
	int		view[4][SIZE];
	int		grid[SIZE + SIZE][SIZE];

	if (argc != 2)
		write(1, "Error\n", 6);
	init_grid(grid);
	if (init_view(view, argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	make_size_flag(grid, view);
	make_one_flag(grid, view, 0);
	if (backtracking(grid, 0, 0, view))
		print_board(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}

void	init_grid(int grid[SIZE][SIZE])
{
	int	i;

	i = 0;
	while (i < SIZE * (SIZE + SIZE))
	{
		grid[i / SIZE][i % SIZE] = 0;
		i++;
	}
}

int	init_view(int view[4][SIZE], char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		while (argv[i] == ' ' || argv[i] == '\t')
			i++;
		if ('1' <= argv[i] && argv[i] <= '0' + SIZE)
		{
			view[count / SIZE][count % SIZE] = argv[i] - '0';
			count++;
		}
		else if (argv[i] == '\0')
			break ;
		else
			return (1);
		i++;
	}
	if (count != SIZE * 4)
		return (1);
	return (0);
}

int	backtracking(int grid[SIZE][SIZE], int x, int y, int view[4][SIZE])
{
	int	num;

	if (y == SIZE)
		return (is_valid_view(grid, view));
	if (x == SIZE)
		return (backtracking(grid, 0, y + 1, view));
	if (grid[y + SIZE][x] == 1)
		return (backtracking(grid, x + 1, y, view));
	num = 1;
	while (num <= SIZE)
	{
		if (is_valid_coor(grid, x, y, num))
		{
			grid[y][x] = num;
			if (backtracking(grid, x + 1, y, view))
				return (1);
			grid[y][x] = 0;
		}
		num++;
	}
	return (0);
}

void	print_board(int grid[SIZE][SIZE])
{
	int		i;
	int		ii;
	char	temp;

	i = 0;
	while (i < SIZE)
	{
		ii = 0;
		while (ii < SIZE)
		{
			temp = grid[i][ii] + '0';
			write(1, &temp, 1);
			if (ii < SIZE - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			ii++;
		}
		i++;
	}
}
