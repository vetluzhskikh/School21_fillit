/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:09:21 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/19 18:23:22 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		if (*((unsigned char*)src) == (unsigned char)c)
		{
			(*(unsigned char*)dest++) = (unsigned char)c;
			return (dest);
		}
		*((unsigned char*)dest++) = *((unsigned char*)src++);
		i++;
	}
	return (NULL);
}
