/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:29:46 by gnelson           #+#    #+#             */
/*   Updated: 2020/02/22 17:44:20 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BLOCK '#'
# define EMPTY '.'
# define NEWLINE '\n'
# define TETRI_SIZE 20
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
typedef struct	s_tetri
{
	char		**shape;
	t_point		*start;
	int			width;
	int			height;
}				t_tetri;
typedef struct	s_square
{
	size_t		size;
	char		**rows;
}				t_square;
t_square		*create_square(size_t size);
void			print_str_square(char	**square);
void			free_square(t_square **square);
void			update_square(t_square **square, char **rows);
t_point			*create_point(int len);
t_point			*create_point_fromxy(int x, int y);
void			free_point(t_point **point);
void			free_minmax_points(t_point ***points);
t_tetri			*create_tetrimino(const char *raw_shape, const char fill);
t_list			*lstnew_tetri(const char *str, char fill);
char			**create_tetrimno_shape(int height, int width);
void			place_a_tetrimino(t_tetri *tetrimino, t_square *square,
									t_point *point);
void			remove_a_tetrimino(t_tetri *tetrimino, t_square *square);
void			lstdel_tetri(void *content, size_t content_size);
void			free_tetrimino(t_tetri **tetri);
int				validate_tetrimino(const char *shape, t_point ***points);
int				lstadd_tetri(t_list **head, t_list **tail, char *t_str,
								int t_count);
int				check_tetrimino_fits(t_tetri *tetrimino, t_square *square,
									t_point *point);
t_tetri			*create_tetrimino(const char *raw_shape, const char fill);
t_list			*get_tetriminoes_from_file(const char *filename);
void			print_usage_msg(const char *prog_name);
int				solve(const char *filename);
int				get_next_point(t_point **point, char **square);
int				solve_a_square(t_square *square, t_list **block,
								t_point *p_start);

#endif
