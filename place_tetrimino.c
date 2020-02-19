/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:21:09 by gnelson           #+#    #+#             */
/*   Updated: 2020/02/19 20:46:20 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int		tetrimino_xshift(t_tetri *tetri)
{
	int x_shift;

	x_shift = 0;
	while ((tetri->shape)[0][x_shift] == '.')
	{
		x_shift++;
	}
	return (x_shift);
}

int		check_tetrimino_max(t_tetri *tetrimino, t_square *square,
							t_point *point)
{
	if ((point->y + tetrimino->height <= (int)square->size) &&
		(point->x - tetrimino_xshift(tetrimino) +
		tetrimino->width <= (int)square->size))
		return (1);
	return (0);
}

int		check_tetrimino_fits(t_tetri *tetrimino, t_square *square,
							t_point *point)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_square;

	tetri_shape = tetrimino->shape;
	str_square = square->rows;
	if (check_tetrimino_max(tetrimino, square, point) != 1)
		return (0);
	y = 0;
	while (tetri_shape[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (!(str_square[y + point->y][x - tetrimino_xshift(tetrimino) +
				point->x] == '.' ||
				tetri_shape[y][x] == '.'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	place_a_tetrimino(t_tetri *tetrimino, t_square *square,
							t_point *point)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_square;

	y = 0;
	tetri_shape = tetrimino->shape;
	str_square = square->rows;
	while (tetri_shape[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (tetri_shape[y][x] != '.')
			{
				str_square[y + point->y][x - tetrimino_xshift(tetrimino) +
				point->x] = tetri_shape[y][x];
			}
			x++;
		}
		y++;
	}
	tetrimino->start->x = (point->x) - tetrimino_xshift(tetrimino);
	tetrimino->start->y = point->y;
}

void	remove_a_tetrimino(t_tetri *tetrimino, t_square *square)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_square;

	y = 0;
	tetri_shape = tetrimino->shape;
	str_square = square->rows;
	while ((tetrimino->shape)[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (tetri_shape[y][x] != '.')
			{
				str_square[y + tetrimino->start->y]
				[x + tetrimino->start->x] = '.';
			}
			x++;
		}
		y++;
	}
}
