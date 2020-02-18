/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:29:51 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/22 14:23:33 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	if ((unsigned char*)dest <= (unsigned char*)src)
	{
		while (i < size)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	else
	{
		while (size > 0)
		{
			--size;
			((unsigned char*)dest)[size] = ((unsigned char*)src)[size];
		}
	}
	return (dest);
}
