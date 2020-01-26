/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:24:32 by gnelson           #+#    #+#             */
/*   Updated: 2020/01/24 21:08:14 by nyaacc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "points.h"

t_point		*create_point(int len)
{
	t_point *point;

	if ((point = (t_point *)ft_memalloc(sizeof(*point))))
	{
		point->x = len % 5;
		point->y = ((len + 5) / 5);
		if (point->y > 0)
			point->y -= 1;
	}
	return (point);
}

void		free_point(t_point **point)
{
	if (!point)
		return ;
	free(*point);
	*point = NULL;
}

void		free_minmax_points(t_point ***points)
{
	if (!points)
		return ;
	free_point(*points + 1);
	free_point(*points);
	free(*points);
	*points = NULL;
}
