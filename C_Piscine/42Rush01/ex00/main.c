/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyole <sub09065@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:01:06 by dongyole          #+#    #+#             */
/*   Updated: 2024/08/21 14:40:15 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	makeview(char *argv[], int view[4][4]);
void	zeroarray(int array[4][4]);
void	printarray(int board[4][4]);
int		check_column_status(int board[4][4], int view[4][4]);
int		check_row_status(int board[4][4], int view[4][4]);

int	check_dup(int row, int col, int board[4][4], int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((board[row][i] == num) || (board[i][col] == num))
			return (0);
		i++;
	}
	return (1);
}

int	count_view(int line[4])
{
	int	cnt;
	int	i;
	int	peak;

	cnt = 0;
	i = 0;
	peak = 0;
	while (i < 4)
	{
		if (line[i] > peak)
		{
			peak = line[i];
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int	check_status(int board[4][4], int view[4][4])
{
	if ((check_column_status(board, view)) == 0)
		return (0);
	if ((check_row_status(board, view)) == 0)
		return (0);
	return (1);
}

int	backtrack(int row, int col, int board[4][4], int view[4][4])
{
	int	num;

	num = 1;
	if (row == 4)
		return (check_status(board, view));
	if (col == 4)
		return (backtrack(row + 1, 0, board, view));
	while (num <= 4)
	{
		if (check_dup(row, col, board, num))
		{
			board[row][col] = num;
			if (backtrack(row, col + 1, board, view))
				return (1);
		}
		num++;
		board[row][col] = 0;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		board[4][4];
	int		view[4][4];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	zeroarray(board);
	zeroarray(view);
	makeview(argv, view);
	if (view[3][3] == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else if (backtrack(0, 0, board, view))
		printarray(board);
	else
		write(1, "Error\n", 6);
	return (0);
}
