/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:57:50 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/10 19:13:28 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	length;
	size_t	lsrc;

	length = ft_strnlen(dest, size);
	lsrc = ft_strlen(src);
	if (length == size)
		return (length + lsrc);
	else if (lsrc < size - length)
		ft_memcpy(dest + length, src, lsrc + 1);
	else
	{
		ft_memcpy(dest + length, src, size - length - 1);
		dest[size - 1] = '\0';
	}
	return (length + lsrc);
}
