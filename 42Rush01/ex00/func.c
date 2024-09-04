/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyole <sub09065@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:02:00 by dongyole          #+#    #+#             */
/*   Updated: 2024/08/21 15:36:19 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_view(int line[4]);

int	check_column_status(int board[4][4], int view[4][4])
{
	int	line[4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			line[j] = board[j][i];
		}
		if (count_view(line) != view[0][i])
			return (0);
		j = 0;
		while (j < 4)
		{
			line[j] = board[3 - j][i];
			j++;
		}
		if (count_view(line) != view[1][i])
			return (0);
		i++;
	}
	return (1);
}

int	check_row_status(int board[4][4], int view[4][4])
{
	int	line[4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			line[j] = board[i][j];
		}
		if (count_view(line) != view[2][i])
			return (0);
		j = 0;
		while (j < 4)
		{
			line[j] = board[i][3 - j];
			j++;
		}
		if (count_view(line) != view[3][i])
			return (0);
		i++;
	}
	return (1);
}

void	makeview(char *argv[], int view[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*argv[1])
	{
		if (*argv[1] == ' ')
			argv[1]++;
		else if ((*argv[1] >= '1') && (*argv[1] <= '4'))
		{
			view[i][j] = (*argv[1]) - '0';
			j++;
			if (j == 4)
			{
				i++;
				j = 0;
			}
			argv[1]++;
		}
		else
			break ;
	}	
}

void	zeroarray(int array[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			array[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	printarray(int board[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
