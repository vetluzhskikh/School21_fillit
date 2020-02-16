/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:07:38 by gnelson           #+#    #+#             */
/*   Updated: 2020/01/24 21:09:10 by nyaacc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "read.h"
# include "tetrimino.h"
# include "square.h"

void	print_usage_msg(const char *prog_name);
int		solve(const char *filename);
int		get_next_point(t_point **point, char **square);
int		solve_a_square(t_square *square, t_list **block);

#endif
