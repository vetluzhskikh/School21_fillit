/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:34:40 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/21 14:15:06 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	i = ft_strlen(s);
	if (c == '\0')
		return ((char*)(&s[i]));
	while (i + 1 > 0)
	{
		if (s[i] == c)
			return ((char*)(&s[i]));
		--i;
	}
	return (NULL);
}
