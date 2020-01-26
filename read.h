/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:24:35 by gnelson           #+#    #+#             */
/*   Updated: 2020/01/24 21:08:44 by nyaacc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define TETRI_SIZE 20

t_list		*get_tetriminoes_from_file(const char *filename);
#endif
