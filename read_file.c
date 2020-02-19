/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:42:53 by gnelson           #+#    #+#             */
/*   Updated: 2020/02/19 20:46:28 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int		validate_newlines(char *tetrimino_str, int *ends_in_newline)
{
	int newline_placement;

	newline_placement = TETRI_SIZE - 1;
	while (newline_placement > 0)
	{
		if (tetrimino_str[newline_placement] != '\n')
			return (-1);
		newline_placement = newline_placement - 5;
	}
	if (tetrimino_str[TETRI_SIZE] != '\n' && tetrimino_str[TETRI_SIZE] != '\0')
		return (-1);
	if (tetrimino_str[TETRI_SIZE] != '\0')
		*ends_in_newline = 1;
	else
		*ends_in_newline = 0;
	return (0);
}

int		check_tetrimino_count(int count)
{
	if (count > 26 || count < 0)
		return (-1);
	return (0);
}

t_list	*read_tetriminoes(int fd)
{
	char	*tetrimino_str;
	int		ends_in_newline;
	int		tetri_cnt;
	t_list	*tail;
	t_list	*head;

	tetrimino_str = ft_strnew(TETRI_SIZE + 1);
	tetri_cnt = 0;
	while (read(fd, tetrimino_str, (TETRI_SIZE + 1)))
	{
		if (validate_newlines(tetrimino_str, &ends_in_newline) == -1 ||
			check_tetrimino_count(tetri_cnt + 1) == -1)
			return (NULL);
		tetrimino_str[TETRI_SIZE] = '\0';
		if (lstadd_tetri(&head, &tail, tetrimino_str, tetri_cnt) == -1)
			return (NULL);
		ft_bzero(tetrimino_str, TETRI_SIZE + 1);
		tetri_cnt++;
	}
	ft_strdel(&tetrimino_str);
	if (tetri_cnt == 0 || ends_in_newline == 1)
		return (NULL);
	return (head);
}

t_list	*get_tetriminoes_from_file(const char *filename)
{
	int		fd;
	t_list	*tetri_lst;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	if (!(tetri_lst = read_tetriminoes(fd)))
	{
		close(fd);
		return (NULL);
	}
	if ((close(fd) == -1))
		return (NULL);
	return (tetri_lst);
}
