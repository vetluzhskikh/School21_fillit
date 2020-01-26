/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:51:01 by gnelson           #+#    #+#             */
/*   Updated: 2020/01/24 21:09:35 by nyaacc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H
# include <string.h>

typedef struct	s_square
{
	size_t		size;
	char		**rows;
}				t_square;
t_square		*create_square(size_t size);
void			print_str_square(char	**square);
void			free_square(t_square **square);
void			update_square(t_square **square, char **rows);
#endif
