/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetraminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:11:21 by gnelson           #+#    #+#             */
/*   Updated: 2019/12/22 15:32:47 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         error_print(int ac)
{
	ft_putstr("usage: /fillit source_file\ncommon_mistakes: not 1 but ");
	ft_putnbr(ac);
	ft_putstr(" source files\n");
	return (-1);
}

int         main(int ac, char **av)
{
	int     fd;
	char    *tetramino;
	int     i;

	i = 0;
	if (ac != 2)
		return (error_print(ac));
	if ((fd = open(av[1], O_RDONLY) <= 0))
		return (-1);
	read(fd, tetramino, MAX_READ);
	
}