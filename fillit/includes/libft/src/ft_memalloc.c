/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:56:55 by gnelson           #+#    #+#             */
/*   Updated: 2020/01/24 20:06:51 by nyaacc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*memory;

	if (size)
	{
		memory = (void *)malloc(sizeof(*memory) * (size));
		if (memory)
		{
			ft_memset(memory, 0, size);
			return (memory);
		}
	}
	return (NULL);
}
