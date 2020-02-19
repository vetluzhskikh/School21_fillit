/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:41:04 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/17 22:09:31 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*lstdel(t_list *tmp)
{
	t_list			*next;

	if (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (!tmp)
				tmp = next;
			next = tmp->next;
			free(tmp);
			tmp = NULL;
		}
	}
	return (tmp);
}

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*newlst;
	t_list			*tmp;

	newlst = NULL;
	tmp = NULL;
	if (!lst || !f)
		return (NULL);
	newlst = f(lst);
	if (!(newlst = ft_lstnew(newlst->content, newlst->content_size)))
		return (NULL);
	lst = lst->next;
	tmp = newlst;
	while (lst)
	{
		newlst->next = f(lst);
		if (!(newlst->next = ft_lstnew((newlst->next)->content,
		(newlst->next)->content_size)))
			return (lstdel(tmp));
		newlst = newlst->next;
		lst = lst->next;
	}
	return (tmp);
}
