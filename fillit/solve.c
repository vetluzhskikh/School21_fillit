/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:40:38 by gnelson           #+#    #+#             */
/*   Updated: 2020/02/18 20:45:06 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/includes/libft.h"
#include "../includes/points.h"
#include "../includes/read.h"
#include "../includes/square.h"
#include "../includes/tetrimino.h"

int				get_next_point(t_point **point, char **square)
{
	if (!square)
		return (0);
	(*point)->x = (*point)->x + 1;
	while (square[(*point)->y] != NULL)
	{
		while (square[(*point)->y][(*point)->x] != '\0')
		{
			if (square[(*point)->y][(*point)->x] == '.')
				return (1);
			(*point)->x = (*point)->x + 1;
		}
		(*point)->y = (*point)->y + 1;
		(*point)->x = 0;
	}
	return (0);
}

static int		if_get_next_point(t_point **p_start)
{
	(*p_start)->x = 0;
	(*p_start)->y = 0;
	return (0);
}

int				solve_a_square(t_square *square, t_list **block,
			t_point *p_start)
{
	int			found;
	t_point		*p_next;

	found = 0;
	if (!block || !*block)
		return (1);
	while ((!(found = check_tetrimino_fits((t_tetri *)(*block)->content,
			square, p_start)) && get_next_point(&p_start, square->rows)))
		;
	if (!found)
		return (0);
	place_a_tetrimino((t_tetri *)(*block)->content, square, p_start);
	p_next = create_point(0);
	if (!solve_a_square(square, &((*block)->next), p_next))
	{
		remove_a_tetrimino((t_tetri *)(*block)->content, square);
		if (!get_next_point(&p_start, square->rows))
			return (if_get_next_point(&p_start));
		free(p_next);
		return (solve_a_square(square, block, p_start));
	}
	free(p_next);
	return (1);
}

int				solve_squares(t_list **tetri_lst)
{
	t_square	*square;
	t_point		*p_start;
	t_list		*tetri_lst_tail;
	size_t		square_size;

	square_size = 2;
	if (!(square = create_square(square_size)))
		return (0);
	if (!(p_start = create_point(0)))
		return (0);
	while ((tetri_lst_tail = *tetri_lst) &&
			!solve_a_square(square, &tetri_lst_tail, p_start))
	{
		free_square(&square);
		if (!(square = create_square(++square_size)))
			return (0);
		p_start->x = 0;
		p_start->y = 0;
	}
	ft_putstrarr(square->rows);
	free_square(&square);
	free(square);
	free(p_start);
	return (1);
}

int				solve(const char *filename)
{
	t_list		*tetri_lst;

	if (!(tetri_lst = get_tetriminoes_from_file(filename)))
		return (0);
	if (!solve_squares(&tetri_lst))
		return (0);
	ft_lstdel(&tetri_lst, &lstdel_tetri);
	return (1);
}
