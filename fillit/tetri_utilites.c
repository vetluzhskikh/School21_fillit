/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_utilites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:54:17 by gnelson           #+#    #+#             */
/*   Updated: 2020/02/16 20:55:41 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "tetrimino.h"
#include "points.h"

static void	fill_tetrimino(const char *raw_shape, const char fill, t_tetri *new)
{
	int	curr_y;
	int curr_x;

	curr_y = 0;
	curr_x = new->start->x + new->start->y * 5;
	while (curr_y < new->height)
	{
		ft_memcpy(new->shape[curr_y], &raw_shape[curr_x], new->width);
		ft_strcre(new->shape[curr_y], BLOCK, fill);
		curr_y++;
		curr_x += 5;
	}
}

char		**create_tetrimno_shape(int height, int width)
{
	char	**shape;
	int		row;

	if ((shape = (char **)ft_memalloc(sizeof(*shape) * height + 1)))
	{
		row = 0;
		while (row < height)
		{
			if (!(shape[row] = ft_strnew(width)))
			{
				while (--row)
					ft_strdel(&shape[row]);
				free(shape);
				return (NULL);
			}
			ft_memset(shape[row++], EMPTY, width);
		}
		shape[row] = NULL;
	}
	return (shape);
}

void		free_tetrimino(t_tetri **tetri)
{
	int height;

	if (!tetri)
		return ;
	free_point(&((*tetri)->start));
	if ((*tetri)->shape)
	{
		height = 0;
		while (height < (*tetri)->height)
			ft_strdel(&((*tetri)->shape[height++]));
		free((*tetri)->shape);
	}
	free(*tetri);
	*tetri = NULL;
}

t_tetri		*create_tetrimino(const char *raw_shape, const char fill)
{
	t_tetri *tetri;
	t_point **points;

	if (!raw_shape || !(points = (t_point **)ft_memalloc(sizeof(*points) * 2)))
		return (NULL);
	if (!validate_tetrimino(raw_shape, &points))
	{
		free(points);
		return (NULL);
	}
	if ((tetri = (t_tetri *)ft_memalloc(sizeof(*tetri))))
	{
		tetri->height = ((points[1])->y - (points[0])->y) + 1;
		tetri->width = ((points[1])->x - (points[0])->x) + 1;
		tetri->start = points[0];
		if (!(tetri->shape = create_tetrimno_shape(
								tetri->height, tetri->width)))
			return (NULL);
		fill_tetrimino(raw_shape, fill, tetri);
	}
	free(points[1]);
	free(points);
	return (tetri);
}
