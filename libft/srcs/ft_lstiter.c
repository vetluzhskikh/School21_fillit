/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:31:46 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/17 21:28:27 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list			*next;

	if (lst && f)
	{
		next = lst->next;
		while (next)
		{
			next = lst->next;
			f(lst);
			lst = next;
		}
	}
}
