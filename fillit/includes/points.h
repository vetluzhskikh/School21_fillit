/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:25:07 by gnelson           #+#    #+#             */
/*   Updated: 2020/02/16 20:40:02 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTS_H
# define POINTS_H
# include <string.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
t_point			*create_point(int len);
t_point			*create_point_fromxy(int x, int y);
void			free_point(t_point **point);
void			free_minmax_points(t_point ***points);
#endif
