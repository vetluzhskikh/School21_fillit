/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:41:47 by gnelson           #+#    #+#             */
/*   Updated: 2020/01/24 21:07:29 by nyaacc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetrimino.h"

/*
** Создаем новый лист под наш тетрис. Провались в tetri_utilites.c
*/

t_list	*lstnew_tetri(const char *str, char fill)
{
	t_tetri	*tetri;
	t_list	*new;

	if (!(tetri = create_tetrimino(str, fill)))
		return (NULL);
	if (!(new = ft_lstnew((void *)tetri, sizeof(*tetri))))
	{
		free_tetrimino(&tetri);
		return (NULL);
	}
	return (new);
}

/*
** Чистим лист
*/

void	lstdel_tetri(void *content, size_t content_size)
{
	(void)content_size;
	free_tetrimino((t_tetri **)&content);
}

/*
** Добавляем новую тетрамину к листу привязывая к ней нужную букву
*/

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