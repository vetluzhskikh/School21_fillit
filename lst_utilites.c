/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utilites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:48:45 by gnelson           #+#    #+#             */
/*   Updated: 2020/02/22 17:45:47 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*lstnew_tetri(const char *str, char fill)
{
	t_tetri	*tetri;
	t_list	*new;

	if (!(tetri = create_tetrimino(str, fill)))
		return (NULL);
	if (!(new = ft_lstnew((void *)tetri, sizeof(*tetri))))
		return (NULL);
	free(tetri);
	return (new);
}

void	lstdel_tetri(void *content, size_t content_size)
{
	(void)content_size;
	free_tetrimino((t_tetri **)&content);
}

int		lstadd_tetri(t_list **head, t_list **tail, char *t_str, int t_count)
{
	if (t_count && ((*tail)->next =
		lstnew_tetri(t_str, 'A' + t_count)))
		*tail = (*tail)->next;
	else if ((*head = lstnew_tetri(t_str, 'A' + t_count)))
		*tail = *head;
	else
	{
		ft_lstdel(head, &lstdel_tetri);
		return (-1);
	}
	return (0);
}
