/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyaacc <nyaacc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:06:40 by gnelson           #+#    #+#             */
/*   Updated: 2020/01/24 20:05:29 by nyaacc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*access_src;
	unsigned char	*edit_dest;

	i = 0;
	access_src = (unsigned char*)src;
	edit_dest = (unsigned char*)dest;
	while (i < n)
	{
		edit_dest[i] = access_src[i];
		i++;
	}
	return (dest);
}

