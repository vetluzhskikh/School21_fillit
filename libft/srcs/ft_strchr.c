/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:51:26 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/19 16:53:27 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*((unsigned char*)s) == (unsigned char)c)
			return ((char*)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char*)s);
	return (NULL);
}
